#include <iostream>
#include "Item.h"

Item::Item()
{
    //setting the default values
    pay_val = 0.0;
    found = true;
    quatity = 0;
    deleted = false;

};

bool Item::populateItem(int D, string n, string nA, double p, string t, vector<int> d, int o)
{
    id = D;
    name = n;
    nameABRV = nA;
    price = p;
    item_type = t;
    deal_id = d;
    scan_order = o;

    return true;
}

bool Item::populateWithCSV(vector<string> data, int s_o)
{
    //lambda function that generates a list of deals that the item is valid for
    auto extractDeals = [](const vector<string>& data)->vector<int>{
        vector<int> result;
        //TODO: abstract out the hardcoding of deal starts on row 5
        int deal_position = 5;
        for(int i=deal_position; i<data.size(); i++){
            if(data[i] == "1"){
                int deal_num = i-(deal_position-1);
                result.push_back(deal_num);
                cout<<"deal found"<< deal_num;
            }
        } 
        return result;      
    };
        
    if(data.size() == 0){
        return false;
    }else{

        id = stoi(data[0]);
        name = data[1];
        nameABRV = data[2];
        price = stod(data[3]);
        item_type = data[4];
        deal_id = extractDeals(data);
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
vector<int> Item::getDealId() const { return deal_id; } 
int Item::getScanOrder() const { return scan_order; }
