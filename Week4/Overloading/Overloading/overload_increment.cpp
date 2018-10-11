//
//  overload_increment.cpp
//  Overloading
//


#include <iostream>

class Counter {
private:
  int count_;
  static int num_increments_;
public:
  Counter(){
    this->count_ = 0;
  }
  Counter(int count){
    this->count_ = count;
  }
  void Display();
  void Inc();
  void operator++(int);
  void Dec();
  void operator--(int);
  
};
int Counter::num_increments_ = 0;

void Counter::Inc(){
  count_++;
  num_increments_++;
}
void Counter::operator++(int){
  this->Inc();
}
void Counter::Dec(){
  count_--;
  num_increments_++;
}
void Counter::operator--(int){
  this->Dec();
}
void Counter::Display(){
  std::cout << "Current count:  " << count_ << '\n';
  std::cout << "Total number increments and decrements:  " << num_increments_ << '\n';
}
int main(){
  Counter counter1 = Counter();
  std::cout << "Current state of counter1 (created with default constructor):   " << '\n';
  counter1.Display();
  Counter counter2 = Counter(200);
  std::cout << "Current state of counter2 (created as Counter(200)):   " << '\n';
  counter2.Display();
  for (int x = 0; x < 85; x++){
    counter1++;
  }
  std::cout << "Current state of counter1 after 85 increments:   " << '\n';
  counter1.Display();
  for (int x = 0; x < 242; x++){
    counter2--;
  }
   std::cout << "Current state of counter2 after 242 decrements:   " << '\n';
  counter2.Display();
  system("PAUSE");
  return 0;
}
