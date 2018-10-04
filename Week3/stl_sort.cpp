#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std; 

int array_length;
int random_number(int, int);
int generate_array(int);
void print_results(int[], int);
std::map<int, int> num_tracker;

int main() 
{
    srand(time(NULL));
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

    cout << "How long would you like the array to be? \n";
    cin >> array_length;
    int numbers[array_length];
    int minimum, maximum;
    cout << "What is the minimum number that could be generated? \n";
    cin >> minimum;
    cout << "What is the maximum number that could be generated? \n";
    cin >> maximum;

    for (int index = 0; index <= array_length - 1; index++){
        numbers[index] = random_number(minimum, maximum);       
    }
    
    sort(numbers, numbers+array_length);
    print_results(numbers, maximum);
    return 0;

} 
// generate a random number
int random_number(int min_num, int max_num){
    int random_int = (min_num + (rand() % max_num));
    num_tracker[random_int] += 1;
    return random_int;
}

void print_results(int array_to_display[], int maximum){
    cout << "Original List, sorted:\n";
    for (int i = 0; i <= array_length - 1; i++){
        cout << "numbers[" << i << "] = " << array_to_display[i] << '\n';
    }
    cout << "Times each number was generated: \n";
    for (int i = 1; i <= maximum; i++){
         cout << i << ": " << num_tracker[i] << '\n';
    }
}