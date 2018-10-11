//
//  money_with_overloading.cpp
//  Overloading
//


#include <iostream>
#include <cmath>

class Money{
 private:
  int dollars_;
  int cents_;
 public:
  Money(){
    this->dollars_ = 0;
    this->cents_ = 0;
  };
  Money(double amount){
    this->dollars_ = (int)amount;
    this->cents_ = fmod(amount, 1);
  };
  Money(int dollars, int cents);
  Money(int dollars);
};

int main(){
  Money amount = Money(11.15);
  return 0;
}

