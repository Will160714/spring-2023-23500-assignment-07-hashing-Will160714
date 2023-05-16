#pragma once
#include "List.h"

class Dictionary{
    private:
        List* dict[100];

    public:
        Dictionary();
        ~Dictionary();
        void insert(Person p);
        int sfold(std::string s);
        Node* retrieve(Person p);
        std::string keys();

};
