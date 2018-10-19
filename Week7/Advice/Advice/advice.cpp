//
//  main.cpp
//  Advice
//
//  Created by Dominic Pimpinella on 10/19/18.
//  Copyright © 2018 Dominic Pimpinella. All rights reserved.
//
#include <iostream>
#include <fstream>


int main() {
  std::ifstream instream("advice.txt");
  if (!instream.fail()){
    std::string last_advice;
    getline(instream, last_advice);
    std::cout << "Found advice file.\n";
    std::cout << "Here is my advice:\n" << last_advice << "\n";
  }
  else {
    std::cout << "No advice file found. This is the first run.\n";
    instream.close();
    std::ofstream outstream("advice.txt", std::ios::in | std::ios::out | std::ios::trunc);
  }
  
  std::ofstream outstream("advice.txt");
  std::string advice;
  std::cout << "Enter your advice for the next user:\n";
  getline(std::cin,advice);
  outstream << advice;
  outstream.close();
  std::cout << std::endl;
  system("PAUSE");
  return 0;
}
