//
//  money_with_overloading.cpp
//  Overloading
//


#include <iostream>
#include <iomanip>
#include <cmath>

class Money{
private:
  int cents_;
  
public:
  Money(){
    this->cents_ = 0;
  };
  
  Money(double amount){
    this->cents_ = amount * 100;
  };
  
  Money(int dollars, int cents){
    this->cents_ = dollars * 100 + cents;
  };
  
  Money(int dollars){
    this->cents_ = dollars * 100;
  };
  Money Add(Money&);
  Money operator+(Money&);
  Money Subtract(Money&);
  Money operator-(Money&);
  bool GreaterThan(Money&);
  bool operator>(Money&);
  bool LessThan(Money&);
  bool operator<(Money&);
  void DisplayPercentage(double);
  double FormatCentsAsDollars(int);
  void PrintMoney();
};

Money Money::Add(Money& other){
  double dollars_and_cents = (this->cents_ + other.cents_) / 100;
  Money sum = Money(dollars_and_cents);
  return sum;
}

Money Money::operator+(Money& other){
  return Add(other);
}

Money Money::Subtract(Money& other){
  double dollars_and_cents = (this->cents_ - other.cents_) / 100;
  Money difference = Money(dollars_and_cents);
  return difference;
}

Money Money::operator-(Money& other){
  return Subtract(other);
}

bool Money::GreaterThan(Money& other){
  bool answer = this->cents_ > other.cents_;
  return answer;
}

bool Money::operator>(Money& other){
  return GreaterThan(other);
}

bool Money::LessThan(Money& other){
  bool answer = this->cents_ < other.cents_;
  return answer;
}

bool Money::operator<(Money& other){
  return LessThan(other);
}

double Money::FormatCentsAsDollars(int amount){
  double amount_to_display = (double)amount / 100;
  return amount_to_display;
}


void Money::DisplayPercentage(double percentage){
  double decimal_percentage = percentage / 100;
  int percent_of_total = (int)(decimal_percentage * cents_);
  FormatCentsAsDollars(percent_of_total);
}

void Money::PrintMoney(){
  double amount_to_display = FormatCentsAsDollars(this->cents_);
  std::cout << std::fixed;
  std::cout << std::setprecision(2);
  std::cout << "$" << amount_to_display << "\n";

}

int main(){
  Money money1 = Money(100);
  Money money2 = Money(200);
  bool answer = money2 < money1;
  std::cout << answer;
  return 0;
}
