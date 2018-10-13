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
  
  friend std::ostream& operator<<(std::ostream&, const Money&);
  friend std::istream& operator>>(std::istream&, Money&);
  
  void DisplayPercentage(double);
  double FormatCentsAsDollars(int);
};

Money Money::Add(Money& other){
  double dollars_and_cents = (double)(this->cents_ + other.cents_) / 100;
  Money sum = Money(dollars_and_cents);
  return sum;
}

Money Money::operator+(Money& other){
  return Add(other);
}

Money Money::Subtract(Money& other){
  double dollars_and_cents = (double)(this->cents_ - other.cents_) / 100;
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

std::ostream& operator<<(std::ostream& os, const Money& money){
  std::cout << std::fixed;
  std::cout << std::setprecision(2);
  os << (double)money.cents_ / 100;
  return os;
}

std::istream& operator>>(std::istream& is, Money& money){
  is >> money.cents_;
  return is;
}

int main(){
  Money my_money = Money(80.72);
  Money your_money;

  std::cout << "Enter an amount of money (in cents)" << "\n";
  std::cin >> your_money;
  std::cout << "\n";
  std::cout << "Your money: $";
  std::cout << your_money << "\n";
  std::cout << "My money: $" << my_money << "\n";
  std::cout << "One of us is richer.\n";
  if (my_money > your_money){
    std::cout << "I have more money.\n";
  }
  if (my_money < your_money){
    std::cout << "You have more money.\n";
  }
  std::cout << "$" << my_money << " + $" << your_money << " = " << my_money + your_money << "\n";
  std::cout << "$" << my_money << " - $" << your_money << " = " << my_money - your_money << "\n";
  system("PAUSE");
}
