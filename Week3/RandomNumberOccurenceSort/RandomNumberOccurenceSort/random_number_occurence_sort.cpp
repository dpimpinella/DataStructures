//
//  Generates an array of numbers, which are then sorted (using STL sort) by number of occurences.
//
//
//  Created by Dominic Pimpinella on 10/3/18.
//  Copyright © 2018 Dominic Pimpinella. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <array>

using namespace std;

int random_number(int, int);
int generate_array(int);
void print_results(int[], int, int);
std::map<int, int> num_tracker;
const int karray_length = 20;

int main()
{
  srand((unsigned int) time(NULL));
  num_tracker[1] = 0;
  num_tracker[2] = 0;
  num_tracker[3] = 0;
  num_tracker[4] = 0;
  num_tracker[5] = 0;
  num_tracker[6] = 0;
  num_tracker[7] = 0;
  num_tracker[8] = 0;
  num_tracker[9] = 0;
  num_tracker[10] = 0;
  
  const int min_num = 1;
  const int max_num = 10;
  int numbers[karray_length];
  
  for (int index = 0; index <= karray_length - 1; index++){
    numbers[index] = random_number(min_num, max_num);
  }
  
  sort(numbers, numbers+karray_length);
  print_results(numbers, max_num, karray_length);
  cout << endl;
  system("PAUSE");
  return 0;
}

int random_number(int min_num, int max_num){
  int random_int = (min_num + (rand() % max_num));
  num_tracker[random_int] += 1;
  return random_int;
}

void print_results(int array_to_display[], int max_num, int array_length){
  cout << "Original List, sorted:\n";
  for (int i = 0; i < array_length; i++){
    cout << "numbers[" << i << "] = " << array_to_display[i] << '\n';
  }
  
  cout << "\n";
  cout << "Times each number was generated: \n";
  for (int i = 1; i <= max_num; i++){
    cout << i << ": " << num_tracker[i] << '\n';
  }
}


