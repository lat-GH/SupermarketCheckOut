#include "Database.h"

#include <iostream> 
#include <fstream> 
#include <sstream>

//using namespace std;

Database::Database(){
    try{
        readCSV();
    }
    catch (const runtime_error& e) { 
        cerr << "Error: " << e.what() << endl; 
    } catch (const exception& e) {
        cerr << "An unexpected error occurred: " << e.what() << endl;
    }
    
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

CSV_row Database::getRecordByName(string name){    
    
    CSV_row new_row;
    vector<string> titles = csv_data[0];

    for (const auto& row : csv_data){
        //TODO: remove the hardcoded search based on the position of name in the database rows
        if(row[1] == name){
            //convert a row of csv into a dictiornay
            for(int i=0;i<titles.size();i++){
                new_row[titles[i]] = row[i];
            }
            return new_row;
        }

    }
    //cout <<"ERROR! " << name << " was NOT FOUND in csv"<<endl;
    CSV_row not_found;
    return not_found;

};
