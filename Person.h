#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    // Constructor
    Person(std::string name, int age);

    // Getters
    std::string getName() const;
    int getAge() const;

    // Setters
    void setName(std::string name);
    void setAge(int age);
};

