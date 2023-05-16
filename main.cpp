#include "Dictionary.h"

int main(){
    //Used the String Folding Hashing Function from https://opendsa-server.cs.vt.edu/ODSA/Books/CS3/html/HashFuncExamp.html
    //Constructor
    std::cout << "Initalized Dictionary Object with Default Constructor" << std::endl;
    Dictionary* test = new Dictionary();
    std::cout << std::endl;
    
    //Insert
    std::cout << "Person to Insert: Patrick, Lin 227534229" << std::endl;
    Person p = Person("Patrick", "Lin", 227534229);
    test -> insert(p);
    std::cout << "Inserted Person" << "\n\n";

    //Keys
    std::cout << "Current Keys" << std::endl;
    std::cout << test -> keys() << std::endl;
    std::cout << "Keys after Inserting New Person" << std::endl;
    p = Person("Shanon", "Wang", 220789123);
    test -> insert(p);
    std::cout << test -> keys() << std::endl;

    //Retrieve
    std::cout << "Retrieving Person from Dictionary" << std::endl;
    Node* value = test -> retrieve(p);
    std::cout << "Name of Retrieved Person: " << (value -> getData()).get_name() << std::endl; 
    std::cout << "ID of Retrieved Person: " << (value -> getData()).get_id() << std::endl; 

    return 0;
}