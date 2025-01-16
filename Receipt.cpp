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
    auto compareByPrice = [](const Item& a, const Item& b) {
    return a.getPrice() < b.getPrice();};

    sort(items_list.begin(), items_list.end(), compareByPrice);
    
}

void Receipt::sortByPrice(vector<Item*>& list) {
    auto compareByPrice = [](const Item* a, const Item* b) {
    return a->getPrice() < b->getPrice();};

    sort(list.begin(), list.end(), compareByPrice);
    
}

void Receipt::sortByDeal() {
    auto compareByDeal = [](const Item& a, const Item& b) {
    return a.getDeal02() < b.getDeal02();};

    sort(items_list.begin(), items_list.end(), compareByDeal);
    
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

    //loop through all the items in receipt
    for(int i=0; i<items_list.size(); i++){
        //passing the refrence --> so it will alter the objects items_list
        Item& currentItem = items_list[i];
        //check if even in the deal
        if(currentItem.getDeal01() == 1){
            
            if(cache.size()==0){
                cache.push_back(currentItem);
            }

            else if (currentItem.getName() == cache.back().getName()){
                //cout<< "currentItem.getName() = "<< currentItem.getName() << " cache.back().getName() = "<<cache.back().getName()<<endl;
                cache.push_back(currentItem);
                
                //when have 3 of the same then discount the final item
                if(cache.size() == 3) {
                    //want the new value to be 0 so discount by its price
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

void Receipt::checkForDeal02(){
    //KEY TO REMEMBER --> must be the cheapest item from the triple that is discounted!

    //sort by deal2 group
    sortByDeal();

    //cache all the items of a deal
    vector<Item*> cache;

     for(int i=0; i<items_list.size(); i++){
        //passing the refrence --> so it will alter the objects items_list
        Item& currentItem = items_list[i];

        //if deal02 = 0 then its not included in this deal
        if(currentItem.getDeal02() > 0){

            if(cache.size()==0){
                cache.push_back(&currentItem);
            }
            else if (currentItem.getDeal02() == cache.back()->getDeal02()){
                cache.push_back(&currentItem);

            }
            //reach end of list or no more of the same
            // dont want to lose currentItem when put in next cache
            else{
                //sort the cahce by price (so can discount the cheapest values)
                sortByPrice(cache);
                // for(int j=0; j<cache.size(); j++){
                //     cout<<cache[j].getName()<<", "<<cache[j].getDeal02()<<endl;
                // }

                //calculate how many to discount 
                // divide into groups of 3 and take the 3 cheapest items
                int num_of_discounts = cache.size() / 3;
                //and discount them from the receipt
                for(int j=0; j<num_of_discounts; j++){
                    discountItemBy(*cache[j], cache[j]->getPrice());
                }

                cache.clear();
                cache.push_back(&currentItem);
            }

        }

        

        
        
     }
     //checks if the cache isw worth sorting out
     if(cache.size()>2){
        sortByPrice(cache);
        int num_of_discounts = cache.size() / 3;
        //and discount them from the receipt
        for(int j=0; j<num_of_discounts; j++){
            discountItemBy(*cache[j], cache[j]->getPrice());
        }

     }
    

    //sort back into the scan order
    sortByScanOrder();


}

void Receipt::prettyPrintReceipt() {
    // Empty implementation
}



