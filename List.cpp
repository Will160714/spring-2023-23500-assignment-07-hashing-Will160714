#include "List.h"
#include "Node.h"

List::List(){
    head = nullptr;
}

List::~List(){
    Node *walker = head;
    Node *trailer = nullptr;
    while(walker != nullptr){
        trailer = walker;
        walker = walker -> getNext();
        delete trailer;
    }
}

void List::insert(Person data){
    Node *tmp = new Node(data);
    //Put in Beginning
    tmp -> setNext(head);
    head = tmp;
}

std::string List::toString(){
    Node *tmp = head;
    std::string result = "";
    while(tmp != nullptr){
        result = result + (tmp -> getData()).get_name() + "\n";
        tmp = tmp -> getNext();
    }
    return result;
}

int List::length(){
    int counter = 0; 
    while(head != nullptr){
        head = head -> getNext();
        counter++;
    }
    return counter;
}

/*
  When working with Linked List, remember you have to keep check of the previous and current
*/
void List::insert(int loc, Person data){
    Node *walker, *trailer;
    walker = head; //Start of the List
    trailer = nullptr; //Always one behind walker
    Node *newNode = new Node(data);
    while(loc > 0 && walker != nullptr){
        loc--;
        trailer = walker;
        walker = walker -> getNext();
    }

    if(loc > 0)
        throw std::out_of_range("Our insert is out of range.");

    if(trailer == nullptr){
        newNode -> setNext(head);
        head = newNode;
    }
    else{
        newNode -> setNext(walker);
        trailer -> setNext(newNode);
    }
}

Node* List::contains(Person item){
    Node *tmp = head; 
    while(tmp != nullptr){
        if((tmp -> getData()).get_id() == item.get_id() && (tmp -> getData()).get_name() == item.get_name())
            return tmp;
        tmp = tmp -> getNext();
    }
    return tmp;
}

void List::remove(int loc){
    Node *walker = head;
    Node *tailer = nullptr;
    for(int x = 0; x < loc; x++){
        tailer = walker;
        walker = walker -> getNext();
    }

    if(walker == nullptr)
        throw std::out_of_range("Tried to remove out of range");

    if(tailer == nullptr){
        head = walker -> getNext();
    }
    else{
        tailer -> setNext(walker -> getNext());
    }

    delete walker;
}