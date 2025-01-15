#ifndef DATABASE_H
#define DATABASE_H
#pragma once

#include<vector>
#include <string>
#include <optional>
using namespace std;

class Database
{
private:
    vector<vector<string>> csv_data;
    string filename = "SuperMarketStock.csv";
    
public:
    Database();
    void readCSV();
    vector<string> getRecordByName(string item_name);

   
};


#endif