#include "Item.h"

Item::Item(int D, string n, string nA, float p, string t, int d, int o)
{
    id = D;
    name = n;
    nameABRV = nA;
    price = p;
    item_type = t;
    deal_id = d;
    scan_order = o;
    
    //setting the default values
    // pay_val = 0.0;
    // found = false;
    // quatity = 0;
    // deleted = false;


};