#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

class Money{
public:
        Money();
        Money(int theDollars, int theCents);
        Money(int theDollars);

private:
        int dollars;
        int cents; 
};

Money::Money(): dollars(0), cents(0){

}
Money::Money(int theDollars, int theCents): dollars(theDollars), cents(theCents){

}
Money::Money(int theDollars): dollars(theDollars), cents(0){

}

int main(){
    return 0;
}
