#include <iostream>
#include "Item.h"

Item::Item()
{
    //setting the default values
    pay_val = 0.0;
    quatity = 0;
    deleted = false;
    discounted_deal01 = false;
    discounted_deal02 = false;

};

// Item::Item(string n)
// {
//     name = n;
//     pay_val = 0.0;
//     quatity = 0;
//     deleted = false;
//     discounted_deal01 = false;
//     discounted_deal02 = false;

// };


//takes a row of CSV data and inputs it into the item
bool Item::populateWithData(CSV_row data, int s_o)
{        
    if(data.size() == 0){
        return false;
    }else{

        //add the column names to the CSV_row type
        id = stoi(data["ID"]);
        name = data["NAME"];
        nameABRV = data["NAMEABRV"];
        price = stod(data["PRICE"]);
        pay_val = stod(data["PRICE"]);
        item_type = data["ITEMTYPE"];
        deal01 = stoi(data["DEAL1"]);
        deal02 = stoi(data["DEAL2"]);
        scan_order = s_o;

        return true;
    };
    
    
}


//getters
int Item::getId() const { return id; } 
string Item::getName() const { return name; } 
string Item::getNameABRV() const { return nameABRV; } 
double Item::getPrice() const { return price; } 
string Item::getItemType() const { return item_type; } 
int Item::getDeal01() const { return deal01; } 
int Item::getDeal02() const { return deal02; } 
int Item::getScanOrder() const { return scan_order; }
