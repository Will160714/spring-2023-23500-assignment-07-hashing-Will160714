#include "Dictionary.h"
#include <cmath>

Dictionary::Dictionary(){
    for(int x = 0; x < 100; x++){
        dict[x] = new List();
    }
}

Dictionary::~Dictionary(){
    for(int x = 0; x < 100; x++){
        delete dict[x];
        dict[x] = nullptr;
    }
}

int Dictionary::sfold(std::string s) {
    int sum = 0;
    int mul = 1;
    for(int i = 0; i < s.length(); i++){
        mul = (i % 4 == 0) ? 1 : mul * 256;
        sum += s[i] * mul;
    }
    return (int)(abs(sum) % 100);
}

void Dictionary::insert(Person p){
    int index = sfold(p.get_name());
    dict[index] -> insert(p);
}

Node* Dictionary::retrieve(Person p){
    int index = sfold(p.get_name());
    return dict[index] -> contains(p);
}

std::string Dictionary::keys(){
    std::string keys = "";
    for(int x = 0; x < 100; x++){
        keys = keys + dict[x] -> toString();
    }
    return keys;
}