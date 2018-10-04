#include <iostream>

using namespace std;

int gcd(int num, int den);
void reduce(int num, int den);

int main(){

    int numerator;
    int denominator;
    int exit_code = 0;
    int exit_choice = 1;

    while (exit_code != exit_choice){

    cout << "Enter the numerator:     ";
    cin >> numerator;
    cout << "Enter the denominator:    ";
    cin >> denominator;

    reduce(numerator, denominator);
    cout << "Try again? (1 = yes, 0 = exit)" << '\n';
    cin >> exit_choice;
    
    }

}

int gcd(int num, int den) {

    while (den != 0){

        int t = den;
        den = num % den;
        num = t;

    }

    cout << "The greatest common denominator is:     " << num << '\n';
    return num;

}

void reduce(int num, int den){

   int greatest_denominator = gcd(num, den);
   cout << "The reduced fraction is:     " << num/greatest_denominator << "/" << den/greatest_denominator << '\n';

}