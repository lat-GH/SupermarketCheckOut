using namespace std;
#include <iostream>
#include <string>

#include "Item.h"
#include "Database.h"

int main() {
    cout<<"Hello Main"<<endl;

    //int id, string name,string nameABRV,float price,string item_type,int deal_id,int scan_order
    //Item x(1234, "apple", "AP",1.3,"fruit",1,1);

    Database x;
    vector<string> result = x.getRecordByName("apple");

    // Print the vector
    for(const auto& element : result){ 
        cout << element << ", "; 
    }

    

    return 0;
}
