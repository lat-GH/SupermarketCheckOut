#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>
#include "GloablTypes.h"

using namespace std;

class Item{
    private:
        int id;
        string name;
        string nameABRV;
        double price;       
        string item_type;
        int deal01;
        int deal02;
        int scan_order;
        
    
    public:
        double pay_val;
        int quatity;
        bool deleted;
        bool discounted_deal01;
        bool discounted_deal02;


        //constructor
        Item();
        Item(string name);
        //bool populateItem(int id, string name,string nameABRV,double price,string item_type,vector<int> d,int scan_order);
        bool populateWithCSV(CSV_row data, int scan_order);

        int getId() const;
        string getName() const; 
        string getNameABRV() const; 
        double getPrice() const; 
        string getItemType() const; 
        int getDeal01() const; 
        int getDeal02() const; 
        int getScanOrder() const;

        


};

#endif