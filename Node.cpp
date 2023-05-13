#include "Node.h"
#include <iostream>

Node::Node(){
    this -> next = nullptr;
}

Node::Node(Person data){
    this -> data = data;
    this -> next = nullptr;
}

Node::Node(Person data, Node *next){
    this -> data = data;
    this -> next = next;
}

void Node::setData(Person data){
    this -> data = data;
}

void Node::setNext(Node *next){
    this -> next = next;
}

Person Node::getData(){
    return data;
}

Node *Node::getNext(){
    return next;
}