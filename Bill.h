#ifndef BILL_H
#define BILL_H

#include <vector>
#include <string>
#include "Item.h" 
#include "GloablTypes.h"

using namespace std;

class Bill {    

public:
    vector<Item> items_list;
    //double total_price;
    int count;
    
    Bill(); // Constructor
    
    Item* findItem(string item_name);
    void addItem(CSV_row data);
    bool removeItem(string item);
    double calcTotalShop();
    void displayBill();

};

#endif 
