#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>
using namespace std;

class Item{
    private:
        int id;
        string name;
        string nameABRV;
        double price;       
        string item_type;
        vector<int> deal_id;
        int scan_order;
        
    
    public:
        double pay_val;
        bool found;
        int quatity;
        bool deleted;

        //constructor
        Item();
        bool populateItem(int id, string name,string nameABRV,double price,string item_type,vector<int> d,int scan_order);
        bool populateWithCSV(vector<string> data, int scan_order);

        int getId() const;
        string getName() const; 
        string getNameABRV() const; 
        double getPrice() const; 
        string getItemType() const; 
        vector<int> getDealId() const; 
        int getScanOrder() const;

        


};

#endif