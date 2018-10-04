#include <iostream>
#include <math.h>
using namespace std;

int main() {
    double radius;
    double volume;
    double force;
    double weight;
    const double pi = 3.141592;
    int close;

    close = 1;
        while (close == 1){
            cout << "Enter the radius of the sphere: ";
            cin >> radius;
            cout << "Enter the weight of the sphere: ";
            cin >> weight;
            volume = 4/3 * pi * pow (radius, 3);
            force = volume * 62.4;
            if (force > weight){
                cout << "It floats!";
            } else {
                cout << "It sinks!";
            }
            cout << "Enter 1 to continue, enter 0 to exit";
            cin >> close;
        }    
    return 0;
}