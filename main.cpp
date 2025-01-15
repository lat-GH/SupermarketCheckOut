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
    Item user_item;


    string user_input;
    cout << "Enter an item to buy: ";
    cin >> user_input;

    vector<string> result = x.getRecordByName(user_input);
    
    // tests if it found the item
    if(result.size() == 0){
        cout<<"name not found in database"<<endl;
    }else{
        user_item.populateWithCSV(result,1);
        cout << "Items details = " <<endl;
        // Print the vector
        for(const auto& element : result){ 
            cout<< element << ", "; 
        }

        cout << "Item pay_val = " << user_item.getName()<<endl;

    }

    

    

    return 0;
}
