using namespace std;
#include <iostream>
#include <string>

#include "Item.h"
#include "Database.h"
#include "Bill.h"


int main() {
    cout<<"Hello Main"<<endl;

    bool scanning = true;

    Database d;
    Bill bill;

    while(scanning){
        string user_input;
        cout << "Enter an item to buy: ";
        cin >> user_input;

        //testing if the user wants to end the scanning
        if(user_input == "PAY" || user_input == "pay"){
            scanning = false;
        }else{
             CSV_row result = d.getRecordByName(user_input);

            // tests if it found the item
            if(result.size() == 0){
                cout<<"name not found in database"<<endl;
            }else{
                bill.addItem(result);

                bill.displayBill();
                cout << "total shop = $"<<bill.calcTotalShop()<<endl;

            }

        }

       



    }

    

    return 0;
}
