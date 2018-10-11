#include <iostream>
#include <cstdlib>
using namespace std;

int numIncrements;

class Counter{

public:
    Counter();
    // initialize to 0
    Counter(int startingNum);
    // initialize to given number
    Counter operator++();
    Counter operator++(int);
    Counter operator--();
    Counter operator--(int);
    void display();
    void inc();
    void dec();

private: 
    int count;
    int numIncrements;
};

int main(){
    ::numIncrements = 0;
    Counter a;
    Counter b(200);

    for (int x = 0; x < 85; x = x + 1) {
        a.inc();
    }
    for (int y = 0; y < 242; y = y + 1) {
        b.dec();
    }
    a.display();
    b.display();
    return 0;
}
Counter::Counter():count(0){

}
Counter::Counter(int startingNum)
    :count(startingNum){

    }
Counter Counter::operator++(int ignore){
    int temp = count++;
    return Counter(temp);
}
Counter Counter::operator--(int ignore){
    int temp = count--;
    return Counter(temp);
}

void Counter::display(){
    cout << "Number of increments and decrements: " << numIncrements << "\n";
    cout << "Current state of counter: " << count << "\n";
//    system("PAUSE");
}

void Counter::inc(){
    count++;
    numIncrements++;
}
void Counter::dec(){
    count--;
    numIncrements++;
}

