#include "Bill.h"

// Constructor definition
Bill::Bill() : total_price(0.0), count(0) {
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
Item Bill::buildItem(CSV_row data) {
    Item x;
    x.populateWithCSV(data,count);
    return x; 
}

// Method to add an item to the list
bool Bill::addItem(Item item) {

    //not sure when it would return false? How would it not add 
    return true; 
}

// Method to remove an item from the list
bool Bill::removeItem(Item item) {
    return true; // Simple return statement
}
