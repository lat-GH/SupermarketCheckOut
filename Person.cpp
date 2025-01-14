#include "Person.h"

// Constructor
Person::Person(std::string name, int age) : name(name), age(age) {}

// Getters
std::string Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}

// Setters
void Person::setName(std::string name) {
    this->name = name;
}

void Person::setAge(int age) {
    this->age = age;
}
