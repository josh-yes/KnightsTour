// Josh Schmitz
// project_perf.h
// April 2021
// Runs performance tests for knights tour algorithms

#include <stdlib.h>
#include <iostream>
#include <chrono>
#include <string>
#include "knights_tour.h"

using namespace std;
using namespace std::chrono;

double warndorffsTour(int size);
double backtrackTour(int size);

// outputs the time it takes to run Wardorff's algorithm and a backtracking
//  algorithm on boards of different sizes
int main(int argc, char* argv[]) {
    // validate command line args
    if (argc != 2 || (argv[1][0] != '1' && argv[1][0] != '2')) {
        cout << "error: invalid command line argument (usage: " << argv[0]
             << " test-number (1 or 2))" << endl;
        exit(1);
    }

    // first test - Warndorff's and backtracking algorithms
    if (argv[1][0] == '1') {
        int start = 5;
        int stop = 8;

        cout << "# Column 1: Board Size" << endl
             << "# Column 2: Backtrack Tour Completion Time" << endl
             << "# Column 3: Warndorff's Tour Completion Time" << endl;
        
        for (int size = start; size <= stop; ++size) {
            double warndorffsTime = warndorffsTour(size);
            double backtrackTime = backtrackTour(size);
            
            cout << size << " " << backtrackTime << " " << warndorffsTime << endl;
        }
    } else { // second test - just Warndorff's algorithm
        int start = 5;
        int stop = 100;

        cout << "# Column 1: Board Size" << endl
             << "# Column 2: Warndorff's Tour Completion Time" << endl;

        for (int size = start; size <= stop; ++size) {
            double warndorffsTime = warndorffsTour(size);
            cout << /*size << " " <<*/ warndorffsTime << endl;
        }
    }
}

// returns the time it takes to run Warndorff's algorithm on a board
//  of given size
double warndorffsTour(int size) {
    KnightsTour knightsTour(size);
    auto start = high_resolution_clock::now();
    knightsTour.warnsdorffsTour(make_pair(0, 0));
    auto end = high_resolution_clock::now();

    return duration_cast<microseconds>(end - start).count();
}

// returns the time it takes to run the backtracking algorithm on a
//  board of given size
double backtrackTour(int size) {
    KnightsTour knightsTour(size);
    auto start = high_resolution_clock::now();
    knightsTour.backtrackTour(make_pair(0, 0));
    auto end = high_resolution_clock::now();

    return duration_cast<microseconds>(end - start).count();
}