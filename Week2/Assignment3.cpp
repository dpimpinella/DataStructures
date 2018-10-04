#include <iostream>
#include <iomanip>
#include <map>
#include <time.h>
#include <stdlib.h>
#include <cmath>
using namespace std;

int main() {

    int first_roll;
    int second_roll;
    int sum_of_rolls;
    long num_of_rolls;
    int exit_code = 0;
    int exit_choice = 1;
    int num_sides = 6;
    int min_num = 1;
    int range = num_sides;
    int min_sum = min_num * 2;
    int max_sum = num_sides * 2;
    int times_rolled;
    double real_error;
    double accepted_odds;
    std::map<int, double> odds_map;
    std::map<int, int> roll_tracker;

    roll_tracker[2] = 0;
    roll_tracker[3] = 0;
    roll_tracker[4] = 0;
    roll_tracker[5] = 0;
    roll_tracker[6] = 0;
    roll_tracker[7] = 0;
    roll_tracker[8] = 0;
    roll_tracker[9] = 0;
    roll_tracker[10] = 0;
    roll_tracker[11] = 0;
    roll_tracker[12] = 0;
    
    odds_map[2] = 1./36;
    odds_map[3] = 2./36;
    odds_map[4] = 3./36;
    odds_map[5] = 4./36;
    odds_map[6] = 5./36;
    odds_map[7] = 6./36;
    odds_map[8] = 5./36;
    odds_map[9] = 4./36;
    odds_map[10] = 3./36;
    odds_map[11] = 2./36;
    odds_map[12] = 1./36;

    srand (time(NULL));

    while (exit_code != exit_choice){

        cout << "Please enter the number of rolls you want:    ";
        cin >> num_of_rolls;


        for (long counter = 0; counter < num_of_rolls; counter++) {
            first_roll = (min_num + (rand() % range));
            second_roll = (min_num + (rand() % range));
            sum_of_rolls = first_roll + second_roll;
            roll_tracker[sum_of_rolls] += 1;
        }

        cout << right << setw(10) << "Sum";
        cout << right << setw(10) << "#Rolled";
        cout << right << setw(10) << "Odds";
        cout << right << setw(10) << "%Error" << '\n';

        for (int print_counter = 2; print_counter <= max_sum; print_counter++) {
            
            times_rolled = roll_tracker[print_counter];
            accepted_odds = odds_map[print_counter] * num_of_rolls;
            real_error = ((abs(accepted_odds - times_rolled))/accepted_odds) * 100;
            
            cout << fixed << setprecision(0) << right << setw(10) << print_counter << ':';
            cout << right << setw(10) << times_rolled;
            cout << right << setw(10) << accepted_odds;
            cout << fixed << setprecision(4) << right << setw(10) << real_error << '\n';
            
        }
        roll_tracker.clear();
        cout << "Try again? (1 = Yes, 0 = Exit):     ";
        cin >> exit_choice;

    }    

    return 0;

}