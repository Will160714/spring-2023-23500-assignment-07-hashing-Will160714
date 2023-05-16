#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Dictionary.h"

TEST_CASE("Constructor"){
    Dictionary* test = new Dictionary();
    CHECK(test != nullptr);
    delete test;
}

TEST_CASE("Deconstructor"){
    Dictionary* test = new Dictionary();
    delete test;
    test = nullptr;
    CHECK(test == nullptr);
}

TEST_CASE("Insert & Keys"){
    Dictionary* test = new Dictionary();
    std::cout << test -> keys() << std::endl;
    CHECK(test -> keys() == "");
    Person p = Person();
    test -> insert(p);
    CHECK(test -> keys() == ", \n");
    p = Person("Patrick", "Lin", 227534229);
    test -> insert(p);
    CHECK(test -> keys() == ", \nPatrick, Lin\n");
    p = Person("Justin", "Wu", 24236334);
    test -> insert(p);
    CHECK(test -> keys() == ", \nPatrick, Lin\nJustin, Wu\n");
    delete test;
}

TEST_CASE("Retrieve"){
    Dictionary* test = new Dictionary();
    Person p = Person();
    CHECK(test -> retrieve(p) == nullptr);
    test -> insert(p);
    Node* value = test -> retrieve(p);
    CHECK((value -> getData()).get_id() == p.get_id());
    CHECK((value -> getData()).get_name() == p.get_name());
    p = Person("Patrick", "Lin", 227534229);
    test -> insert(p);
    value = test -> retrieve(p);
    CHECK((value -> getData()).get_id() == p.get_id());
    CHECK((value -> getData()).get_name() == p.get_name());
    delete test;
}