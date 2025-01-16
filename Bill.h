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
    int count;
    
    Bill(); 
    
    void addItem(CSV_row data);
    double calcTotalShop();
    void displayBill();

};

#endif 
