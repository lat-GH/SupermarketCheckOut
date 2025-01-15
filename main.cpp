using namespace std;
#include <iostream>
#include <string>

#include "Item.h"
#include "Database.h"
#include "Bill.h"


int main() {
    cout<<"Hello Main"<<endl;

    //int id, string name,string nameABRV,float price,string item_type,int deal_id,int scan_order
    //Item x(1234, "apple", "AP",1.3,"fruit",1,1);

    Database d;
    Bill bill;


    string user_input;
    cout << "Enter an item to buy: ";
    cin >> user_input;

    CSV_row result = d.getRecordByName(user_input);
    
    // tests if it found the item
    if(result.size() == 0){
        cout<<"name not found in database"<<endl;
    }else{
        bill.addItem(result);
        // cout << "Items details = " <<endl;
        // // Print the vector
        // for(const auto& element : result){ 
        //     cout<< element.first<<"="<< element.second<< ", "; 
        // }

        cout << "name of item 0 on list = "<<bill.items_list[0].getName()<<endl;
        cout << "total shop = $"<<bill.calcTotalShop()<<endl;

    }

    

    

    return 0;
}
