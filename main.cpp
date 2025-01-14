using namespace std;
#include <iostream>
#include <string>


#include "Person.h"
#include "Item.h"

int main() {
    cout<<"Hello Main";
    //int id, string name,string nameABRV,float price,string item_type,int deal_id,int scan_order
    //Item x(1234, "apple", "AP",1.3,"fruit",1,1);

    Person p("Lolly", 25);
    // Print details
    std::cout << "Name: " << p.getName() << std::endl;
    std::cout << "Age: " << p.getAge() << std::endl;

    Item x(1234, "apple", "AP",1.3f,"fruit",1,1);
    cout<<x.found<<endl;

    return 0;
}
