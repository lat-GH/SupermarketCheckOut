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
    void sortByDeal();
    void sortByScanOrder();
    void sortByName();
    void discountItemBy(Item item, double value);
};

#endif // RECEIPT_H
