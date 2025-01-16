#ifndef DATABASE_H
#define DATABASE_H
#pragma once

#include<vector>
#include <string>
#include <optional>
#include "GloablTypes.h"
using namespace std;

class Database
{
private:
    CSV_table csv_data;
    //string filename = "SuperMarketStock.csv";
    string filename = "SuperMarketStock_2.csv";
    
public:
    Database();
    void readCSV();
    CSV_row getRecordByName(string item_name);

   
};


#endif