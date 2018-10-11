//
//  explore_copy.cpp
//  ExploreCopy
//
//  Created by Dominic Pimpinella on 10/5/18.
//  Copyright © 2018 Dominic Pimpinella. All rights reserved.
//

#include <iostream>

using namespace std;

class WrapArrayDeep {
 private:
  char* pch;
 public:
  WrapArrayDeep(){
    pch = new char[5];
    *pch = 97;
    *(pch+1) = 98;
    *(pch+2) = 99;
    *(pch+3) = 100;
    *(pch+4) = 101;
    cout << "Deep copy values:" << endl;
    for(int i = 0; i < 5; i++)
      cout << pch[i] << endl;
    cout << &pch;
    cout << "\n";
  }
  WrapArrayDeep(WrapArrayDeep &wad){
    pch = new char[5];
    *pch = *(wad.pch);
    *(pch+1) = *((wad.pch)+1);
    *(pch+2) = *((wad.pch)+2);
    *(pch+3) = *((wad.pch)+3);
    *(pch+4) = *((wad.pch)+4);
  }
  ~WrapArrayDeep(){
    delete[] pch;
    cout << "Calling destructor for WrapArrayDeep\n";
  }
  char* peek_pch(){
    return pch;
  }
  void change_pch(int index, char c){
    pch[index] = c;
  }
};

class WrapArrayShallow {
 private:
  
 public:
  char* pch;
  WrapArrayShallow(){
    pch = new char[5];
    pch[0] = 'v';
    pch[1] = 'w';
    pch[2] = 'x';
    pch[3] = 'y';
    pch[4] = 'z';
    cout << "Shallow copy values:" << endl;
    for(int i = 0; i < 5; i++)
      cout << *(pch + i) << endl;
    cout << &pch << endl;
    cout << "\n";
  }
  WrapArrayShallow(WrapArrayShallow &was){
    pch = was.pch;
  }
//  ~WrapArrayShallow(){
//    delete[] pch;
//    cout << "Calling destructor for WrapArrayShallow\n";
//  }
  char* peek_pch(){
    return pch;
  }
  void change_pch(int index, char c){
    pch[index] = c;
  }
};

int main() {
  
  WrapArrayDeep wad;
  WrapArrayShallow was;
  
  WrapArrayDeep deep_copy = wad;
  WrapArrayShallow shallow_copy(was);
  
  cout << "Using deep copy:\n";
  cout << "wad1 = " << wad.peek_pch() << endl;
  cout << "wad2, using the copy constructor on wad1 = " << deep_copy.peek_pch() << endl;
  wad.change_pch(0, '%');
  cout << "After changing the first char in wad1 to %: " << endl;
  cout << "wad1 = " << wad.peek_pch() << endl;
  cout << "wad2 = " << deep_copy.peek_pch();
  cout << "\n\n";
  
  cout << "Using shallow copy:\n";
  cout << "was1 = " << was.peek_pch() << endl;
  cout << "was2, using the copy constructor on was1 = " << shallow_copy.peek_pch() << endl;
  was.change_pch(0, '#');
  cout << "After changing the first char in was1 to #:" << endl;
  cout << "was1 = " << was.peek_pch()<< endl;
  cout << "was2 = " << shallow_copy.peek_pch() << endl;
  cout << "\n\n";
  
  
  system("PAUSE");
  return 0;
}
