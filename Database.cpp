#include "Database.h"

#include <iostream> 
#include <fstream> 
#include <sstream>

//using namespace std;

Database::Database(){
    readCSV();
    
};

void Database::readCSV(){
    ifstream file(filename);

    if (!file.is_open()) { 
        cerr << "Error opening file" << endl;
        return;
    } 

    string line;
    while(getline(file, line)){
        stringstream ss(line);
        string value;
        vector<string> row;

        while(getline(ss, value, ',')){
            row.push_back(value);
        }
        csv_data.push_back(row);

    }

    file.close();
    
};

vector<string> Database::getRecordByName(string name){

    for (const auto& row : csv_data){
        //TODO: remove the hardcoded search based on the position of name in the database rows
        if(row[1] == name){
            return row;
        }

    }
    vector<string> not_found = {};
    return not_found;

};
