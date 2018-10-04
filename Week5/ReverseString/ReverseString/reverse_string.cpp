//
//  main.cpp
//  ReverseString
//
//  Created by Dominic Pimpinella on 10/4/18.
//  Copyright © 2018 Dominic Pimpinella. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

void GetUserInput();
void ReverseString(char* user_string);

int main() {
  cout << "This program reverses a string entered by the user using the STL"
          "stack." << endl;
  GetUserInput();
  cout << "\n";
}

void GetUserInput() {
  char* user_string = (char*)malloc(80);
  int control = 1;
  while(control == 1){
  cout << "Enter your string of less than 80 characters followed by an ENTER" <<
    endl;
  cin.getline(user_string,81,'\n');
  ReverseString(user_string);
  cout << "Enter another string? 1 = continue. Anything else to stop." << endl;
  cin >> control;
  cout << "\n";
    
  // cin.ignore() ignores that the enter key is pressed in the line above,
  // allowing for getline() to read in user input
  cin.ignore();
  }
  free(user_string);
}

void ReverseString(char* user_string){
  stack<char> stack;
  for(int i = 0; user_string[i] != '\0'; i++) {
    char c = user_string[i];
    stack.push(c);
  }
  while (!stack.empty()){
    char c = stack.top();
    stack.pop();
    cout << c;
  }
  cout << endl;
}

