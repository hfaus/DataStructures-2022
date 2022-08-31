/**
 * @file LockerDoors_Faus_Hannah.cpp
 * @author Hannah Faus (hfaus@email.sc.edu)
 * @brief Homework-1 for Data Structures and Algorithms
 * @version 0.1
 * @date 2022-08-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <vector>
#include <iostream>
using namespace std;

void hallwaySimulation(bool status[], int numLockers, int numPasses) {
    // simulating all the passes
    for (int i = 1; i <= numPasses; ++i) {
        // simulating a single pass
        for (int j = 0; j < numLockers; ++j) {
            if (j % i == 0) {
                status[j] = !status[j];
            }
        }
    }

    // variable for # of open lockers
    int numOpen = 0;

    // displaying which doors are open and closed AND the # of open locker doors
    for (int k = 0; k < numLockers; ++k) {
        if (status[k] == 0) {
            cout << "Locker " << k+1 << " is closed" << endl;
        } else {
            cout << "Locker " << k+1 << " is open" << endl;
            ++numOpen;
        }
    }

    cout << "The total number of open lockers is " << numOpen << endl;

}


int main() {
    // variables for the number of locker doors and number of passes
    int numLockers;
    int numPasses;

    // user enters info for numLockers and numPasses
    cout << "Please enter the # of locker doors" << endl;
    cin >> numLockers;

    cout << "Please enter the # of passes" << endl;
    cin >> numPasses;

    // checks
    if (numLockers >= 0 && numPasses >= 0) {
        // array for holding the locker closed/opened status - automatically set to 0, so closed is 0
        bool status[numLockers];

        // populating with 0 - they all start closed
        for (int i = 0; i < numLockers; ++i) {
            status[i] = 0;
        }

        // calling hallwaySimulation function
        hallwaySimulation(status, numLockers, numPasses);
        
    } else {
        cout << "The input you entered was invalid. Please try again." << endl;
    }
}