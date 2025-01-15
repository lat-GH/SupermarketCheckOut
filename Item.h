#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Item{
    private:
        int id;
        string name;
        string nameABRV;
        double price;       
        string item_type;
        int deal_id;
        int scan_order;
        
    
    public:
        double pay_val;
        bool found;
        int quatity;
        bool deleted;

        //constructor
        Item(int id, string name,string nameABRV,double price,string item_type,int deal_id,int scan_order);


};

#endif