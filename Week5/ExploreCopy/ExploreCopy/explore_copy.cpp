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
  WrapArrayDeep(){
    pch = new char[5];
    *pch = 97;
    *(pch+1) = 98;
    *(pch+2) = 99;
    *(pch+3) = 100;
    *(pch+4) = 101;
    for(int i = 0; i < 5; i++)
      cout << pch[i] << endl;
  }
  WrapArrayDeep(WrapArrayDeep &wad){
    // correct copy constructor whatever the hell that means
  }
};

class WrapArrayShallow {
 private:
  char* pch;
  WrapArrayShallow(){
    pch = new char[5];
    pch[0] = 'v';
    pch[1] = 'w';
    pch[2] = 'x';
    pch[3] = 'y';
    pch[4] = 'z';
    for(int i = 0; i < 5; i++)
      cout << *(pch + 1) << endl;
  }
  WrapArrayShallow(WrapArrayShallow &was){
    
  }
};

int main() {
  return 0;
}
