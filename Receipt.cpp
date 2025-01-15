#include "Receipt.h"

// Constructor
Receipt::Receipt() {
    // Empty constructor
}

void Receipt::addItem(Item item) {
    items_list.push_back(item);
    count ++;
}

void Receipt::sortByPrice() {
    // Empty implementation
}

void Receipt::sortByDeal() {
    // Empty implementation
}

void Receipt::sortByScanOrder() {
    // Empty implementation
}

void Receipt::sortByName() {
    // Empty implementation
}

void Receipt::discountItemBy(Item item, double value) {
    // Empty implementation
}
