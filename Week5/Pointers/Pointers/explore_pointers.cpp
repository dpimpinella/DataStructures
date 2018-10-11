//
//  explore_pointers.cpp
//  Pointers
//
//  Created by Dominic Pimpinella on 10/4/18.
//  Copyright © 2018 Dominic Pimpinella. All rights reserved.
//

#include <iostream>

using std::cout;
using std::endl;

int main(){
  int i = 7;
  int* pi;
  pi = &i;
  
  cout << "Integer i = " << i << "\n\n";
  
  cout << "pi = " << pi << endl;
  cout << "The dereference of pi = " << *pi << endl;
  cout << "The address pi = " << &pi << endl;
  cout << "The address of i = " << &i << "\n\n";
  
  int** ppi;
  ppi = &pi;
  
  cout << "ppi = " << ppi <<endl;
  cout << "The dereference of ppi = " << *ppi << endl;
  cout << "The address of ppi = " << &ppi << endl;
  cout << "The double dereference of ppi = " << **ppi <<"\n\n";
  system("PAUSE");
}
