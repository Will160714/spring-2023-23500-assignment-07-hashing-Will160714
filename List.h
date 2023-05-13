#pragma once
#include <iostream>
#include "Node.h"

class List{
    private:
        Node *head;
    public:
        List();
        ~List();
        void insert(Person data);
        std::string toString(); // for testing purposes
        std::string get(int loc); //Needs Fixing
        int length(); // the # of elements 
        void insert(int loc, Person data); //0 indexed
        Node* contains(Person item);
        void remove(int loc);
};