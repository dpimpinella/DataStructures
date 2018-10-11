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
  int DollarsPart(double);
  int CentsPart(double);
  
public:
  Money(){
    this->dollars_ = 0;
    this->cents_ = 0;
  };
  
  Money(double amount){
    this->dollars_ = DollarsPart(amount);
    this->cents_ = CentsPart(amount);
  };
  
  Money(int dollars, int cents){
    this->dollars_ = dollars;
    this->cents_ = cents;
  };
  
  Money(int dollars){
    this->dollars_ = dollars;
    this->cents_ = 0;
  };
  
  void DisplayPercentage(double);
};

int Money::DollarsPart(double amount){
  return static_cast<int>(amount);
}

int Money::CentsPart(double amount){
  double double_cents = amount * 100;
  int int_cents = int(round(fabs(double_cents))) % 100;
  if (amount < 0){
    int_cents = -int_cents;
  }
    return int_cents;
}

void Money::DisplayPercentage(double percentage){
  double decimal_percentage = percentage / 100;
  double amount = ((double)dollars_ + (double)cents_ / 100) * decimal_percentage;
  std::cout << percentage << "% of your money is:  $" << amount << '\n';
}

int main(){
  Money money = Money(10);
  money.DisplayPercentage(33);
  return 0;
}
