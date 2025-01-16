#include "Bill.h"
#include <iostream>
#include <iomanip>


Bill::Bill() : count(0) {
}

void Bill::addItem(CSV_row data) {
    Item item;
    //build an Item object from CSV data
    item.populateWithData(data,count);
    items_list.push_back(item);
    count ++;
}

double Bill::calcTotalShop(){
    //calculates based on the pay_val not the price
    double sum = 0;
    for(int i=0; i<items_list.size(); i++){
        sum += items_list[i].pay_val;
    }
    return sum;
}

//loops through all items and displays in a list
void Bill::displayBill(){
    for(int i=0; i<items_list.size(); i++){
        cout <<items_list[i].getScanOrder() <<".) "<<items_list[i].getName() << " = $"<< fixed<<setprecision(2)<<items_list[i].pay_val<<endl;
    }
}

