#include "Bill.h"
#include <iostream>

// Constructor definition
Bill::Bill() : count(0) {
    // Initialize the items_list if needed
}

// Method to find an item by name will return pointer, so Item can be altered
Item* Bill::findItem(string item_name) {

    for(int i=0; i<items_list.size(); i++){
        if(items_list[i].getName() == item_name){
            //retruning the pointer to the item in bill
            return &items_list[i];
        }
    }
    //when item is not found
    return nullptr; 
}

// Method to build an item from CSV data
void Bill::addItem(CSV_row data) {
    Item item;
    item.populateWithData(data,count);
    items_list.push_back(item);
    count ++;
}


// Method to remove an item from the list
bool Bill::removeItem(string item_name) {
    //finds item first
    for(int i=0; i<items_list.size(); i++){
        if(items_list[i].getName() == item_name){
            // wont delete an item from the bill will just set it deleted flag to true
            items_list[i].deleted = true;
            items_list[i].pay_val = -1 * items_list[i].pay_val;
            return true;
        }
    }
    //when item is not found
    return false;
}

double Bill::calcTotalShop(){
    //calculates based on the pay_val not the price
    double sum = 0;
    for(int i=0; i<items_list.size(); i++){
        sum += items_list[i].pay_val;
        // //if not deleted
        // if(!items_list[i].deleted){
            
        // }
    }
    return sum;
}

void Bill::displayBill(){
    for(int i=0; i<items_list.size(); i++){
        cout <<items_list[i].getScanOrder() <<".) "<<items_list[i].getName() << " = $"<< items_list[i].pay_val<<endl;
    }
}

