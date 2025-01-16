#ifndef RECEIPT_H
#define RECEIPT_H

#include <vector>
#include <string>
#include "Bill.h"

class Receipt : public Bill{

public:
    // Constructor
    Receipt();

    void addItem(Item item);
    void sortByPrice();
    void sortByPrice(vector<Item*>& items);
    void sortByDeal();
    void sortByScanOrder();
    void sortByName();
    void discountItemBy(Item& item, double value);
    void checkForDeal01();
    void checkForDeal02();
    void prettyPrintReceipt();
};

#endif // RECEIPT_H
