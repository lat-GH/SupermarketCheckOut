// Your First C++ Program

using namespace std;
#include <iostream>
#include <string>

class Food {
    public:
        float price;
        string name;
};

int main() {
    Food apple;
    apple.name = "pink lady";
    apple.price = 1.30;
    
    cout <<"Item 01 = "<<apple.name<<" £"<<apple.price<< endl;
    return 0;
}
