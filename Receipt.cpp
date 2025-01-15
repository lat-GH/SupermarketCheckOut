#include "Receipt.h"
#include <algorithm>
#include <iostream>

// Constructor
Receipt::Receipt() {
    // Empty constructor
}

void Receipt::addItem(Item item) {
    items_list.push_back(item);
    count ++;
}

void Receipt::sortByPrice() {
    // Empty implementation
}

void Receipt::sortByDeal() {
    // Empty implementation
}

void Receipt::sortByScanOrder() {
    auto compareByOrder = [](const Item& a, const Item& b) {
    return a.getScanOrder() < b.getScanOrder();};

    sort(items_list.begin(), items_list.end(), compareByOrder);
    

}

void Receipt::sortByName() {
    auto compareByName = [](const Item& a, const Item& b) {
    return a.getName() < b.getName();};

    sort(items_list.begin(), items_list.end(), compareByName);
    
}

void Receipt::discountItemBy(Item& item, double value) {
    item.pay_val = item.pay_val - value;    
}

void Receipt::checkForDeal01() {
    //first step is to sort by name
    sortByName();
    vector<Item> cache;

    for(int i=0; i<items_list.size(); i++){
        Item& currentItem = items_list[i];
        if(currentItem.getDeal01() == 1){

            
            
            if(cache.size()==0){
                cache.push_back(currentItem);
            }
        
            else if (currentItem.getName() == cache.back().getName()){
                //cout<< "currentItem.getName() = "<< currentItem.getName() << " cache.back().getName() = "<<cache.back().getName()<<endl;
                cache.push_back(currentItem);

                if(cache.size() == 3) {
                    discountItemBy(currentItem, currentItem.getPrice());
                    cache.clear();
                }
            }
            else{
                cache.clear();
            }
            


        }
    }
    //sort back to scan order again afterwards
    sortByScanOrder();

}

void Receipt::prettyPrintReceipt() {
    // Empty implementation
}



