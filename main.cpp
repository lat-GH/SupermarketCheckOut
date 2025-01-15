using namespace std;
#include <iostream>
#include <string>

#include "Item.h"

int main() {
    cout<<"Hello Main"<<endl;

    //int id, string name,string nameABRV,float price,string item_type,int deal_id,int scan_order
    Item x(1234, "apple", "AP",1.3f,"fruit",1,1);

    cout<<"x.found = "<<x.found<<endl;

    return 0;
}
