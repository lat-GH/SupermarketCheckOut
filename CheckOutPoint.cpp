#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

#include "CheckOutPoint.h"
#include "Item.h"
#include "Database.h"
#include "Bill.h"
#include "Receipt.h"

void CheckOutPoint::runCheckOut(){
    string user_input;
    bool shop = true;
    
    cout << "Welcome to BurySain's\n Live well for more\n"<<endl;
    

    while(shop){
        cout << "Type \'start\' to begin your shop"<<endl;
        cout << "Type \'pay\' to pay for your shop and see receipt"<<endl;
        cout << "Type \'end\' to close the check out point"<<endl;
        cin >> user_input;

        if(user_input == "start"){
            runSingleBill();
        }
        else if(user_input == "end")
        {
            shop=false;
        }      
        
    }

    cout<<"\n\nThank you for shopping at BurySain's\n Live well for more\n"<<endl;


}
        
void CheckOutPoint::runSingleBill(){
    //when the user enters PAY or pay then the scanning will end and
    //the reciept will be displayed
    bool scanning = true;

    Database d;
    Bill b;

    while(scanning){
        string user_input;
        cout <<"\nEnter an item to buy (or pay): ";
        cin >> user_input;

        //testing if the user wants to end the scanning
        if(user_input == "PAY" || user_input == "pay"){
            scanning = false;
        }else{
            //seaching the database to check if item exists
             CSV_row result = d.getRecordByName(user_input);

            // tests if it found the item
            if(result.size() == 0){
                cout<<"---------\'"<<user_input<<"\'"<<" NOT FOUND! "<<endl;
            }else{
                b.addItem(result);
                cout<<endl;
                b.displayBill();
                cout << "\nTOTAL SHOP = $"<<fixed<<setprecision(2)<<b.calcTotalShop()<<endl;
                cout<<endl;

            }

        }

    }

    // when finished scanning checks for deals then calculates the reciept
    Receipt r;
    for(int i=0; i<b.items_list.size(); i++){
        r.addItem(b.items_list[i]);
    }

    r.checkForDeal01();
    r.checkForDeal02();

    r.prettyPrintReceipt();
    
}
