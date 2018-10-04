//
//  explore_pointers.cpp
//  Pointers
//
//  Created by Dominic Pimpinella on 10/4/18.
//  Copyright © 2018 Dominic Pimpinella. All rights reserved.
//

#include <iostream>

using namespace std;

int main(){
  int i = 7;
  int* pi;
  pi = &i;
  
  cout << "Integer i = " << i << endl;
  cout << "The address of the pointer to i, pi = " << pi << endl;
  cout << "The dereferenced pointer to i, *pi = " << *pi << endl;
  
  int** ppi;
  ppi = &pi;
  
  cout << "Pointer to pointer pi, ppi = " << ppi << endl;
  cout << "The address of the pointer to the pointer pi, ppi = " << ppi <<endl;
  cout << "The dereference of the pointer to pointer pi, ppi = " << *ppi << endl;
  cout << "The double dereference of the pointer to pointer pi, ppi = " << **ppi <<endl;
}
