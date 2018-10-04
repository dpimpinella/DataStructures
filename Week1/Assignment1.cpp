#include <iostream>
using namespace std;

int main() {
    double guess;
    double r;
    double input;

    cout << "Enter a number, I will use the Babylonian square root algoritbm until I am within 0.001 of the correct answer:" << '\n'; 
    cin >> input;
    cout << "You entered: " << input << '\n';
    guess = input/2;

    while(guess - r  >= 0.001){
        r= input/guess; 
        guess = (guess + r)/2;
    }
    cout << "The square root of " << input << " " << "is " << guess << " ";
    return 0;
}