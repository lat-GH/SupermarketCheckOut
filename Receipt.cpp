#include "Receipt.h"
#include <algorithm>
#include <iostream>
#include <iomanip>

Receipt::Receipt() {
}

void Receipt::addItem(Item item) {
    items_list.push_back(item);
    count ++;
}

//sorts the items in the Recipet by Price
void Receipt::sortByPrice() {
    auto compareByPrice = [](const Item& a, const Item& b) {
    return a.getPrice() < b.getPrice();};

    sort(items_list.begin(), items_list.end(), compareByPrice);
    
}

//sorts the items in a given vector of items by Price
void Receipt::sortByPrice(vector<Item*>& list) {
    auto compareByPrice = [](const Item* a, const Item* b) {
    return a->getPrice() < b->getPrice();};

    sort(list.begin(), list.end(), compareByPrice);
    
}

//sorts the items in the Reciept by Deal02 group
void Receipt::sortByDeal02() {
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
        //passing the refrence --> so it will alter the objects in Receipt's items_list
        Item& currentItem = items_list[i];
        //check if even in the deal
        if(currentItem.getDeal01() == 1){
            
            if(cache.size()==0){
                cache.push_back(currentItem);
            }

            else if (currentItem.getName() == cache.back().getName()){
                cache.push_back(currentItem);
                
                //when have 3 of the same then discount the final item
                if(cache.size() == 3) {
                    //want the new pay value to be 0 so discount by its price
                    discountItemBy(currentItem, currentItem.getPrice());
                    currentItem.discounted_deal01 = true;
                    cache.clear();
                }
            }
            else{
                cache.clear();
                //make sure the current item is added into a fresh cache
                cache.push_back(currentItem);

            }          

        }
    }
    //sort back to scan order again afterwards
    sortByScanOrder();

}

void Receipt::checkForDeal02(){
    
    //sort by deal02 group
    sortByDeal02();

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
            //CASE: no more of the same
            
            else{
                //sort the cahce by price (so can discount the cheapest values)
                sortByPrice(cache);

                //calculate how many to discount 
                // divide into groups of 3 and take the 3 cheapest items
                //avoids the need of deciding which triples to group the item
                int num_of_discounts = static_cast<int>(cache.size()) / 3;

                //and discount them from the receipt
                for(int j=0; j<num_of_discounts; j++){
                    discountItemBy(*cache[j], cache[j]->getPrice());
                    cache[j]->discounted_deal02 = true;
                }

                cache.clear();
                // dont want to lose currentItem when put in next cache
                cache.push_back(&currentItem);
            }

        }      
     }
     //CASE: reached end of list 
     //checks if the cache is worth sorting out
     if(cache.size()>2){
        sortByPrice(cache);
        int num_of_discounts = static_cast<int>(cache.size()) / 3;
        //and discount them from the receipt
        for(int j=0; j<num_of_discounts; j++){
            discountItemBy(*cache[j], cache[j]->getPrice());
            cache[j]->discounted_deal02 = true;
        }

     }
    

    //sort back into the scan order
    sortByScanOrder();
}

void Receipt::prettyPrintReceipt() {
    cout <<"\n***********Your Receipt*****************\n BurySain's\n Live well for more\n"<<endl;
    double before_discount = 0;
    double total_discount = 0;

    int left_stew = 20;
    int right_stew = 12;

    for(int i=0; i<items_list.size(); i++){
       cout<< left << setw(left_stew) <<items_list[i].getName()<< right << setw(right_stew) <<"$"<< fixed<<setprecision(2)<<items_list[i].getPrice()<<endl;
       before_discount += items_list[i].getPrice();
       
       if(items_list[i].discounted_deal01 ){
            double discount_val = items_list[i].pay_val - items_list[i].getPrice();
            total_discount += discount_val;
            cout<< left << setw(left_stew) <<"DISCOUNT deal01"<< right << setw(right_stew) <<"-$"<< fixed<<setprecision(2)<<discount_val*-1<<endl;
       }
       else if (items_list[i].discounted_deal02)
       {
            double discount_val = items_list[i].pay_val - items_list[i].getPrice();
            total_discount += discount_val;
            cout<< left << setw(left_stew) <<"DISCOUNT deal02"<< right << setw(right_stew) <<"-$"<< fixed<<setprecision(2)<<discount_val*-1<<endl;
       }
       
    }
    cout<<endl;
    
    //if dont save any money then this isn't displayed in the reciept
    if(total_discount < 0){
        cout<< left << setw(left_stew) <<"Before discounts"<< right << setw(right_stew) <<"$"<< fixed<<setprecision(2)<<before_discount<<endl;
        cout<< left << setw(left_stew) <<"Amount saved"<< right << setw(right_stew) <<"-$"<< fixed<<setprecision(2)<<total_discount*-1<<endl;
    }
    cout<<"\nNumber of items bought: "<< count<<endl;
    cout << left << setw(left_stew) <<"BALANCE DUE "<< right << setw(right_stew) <<"$"<< fixed<<setprecision(2)<<calcTotalShop()<<endl;

    cout <<"\n****************************\n"<<endl;
    
} 



