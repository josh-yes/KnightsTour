// Josh Schmitz
// knights_tour.h
// April 2021
// Solves the knights tour problem using Warnsdorff's algorithm
//  and a backtracking approach.


#ifndef KNIGHTSTOUR_H
#define KNIGHTSTOUR_H

#include <iostream>
#include <string>
#include <iomanip>
#include <list>
#include <vector>

using namespace std;

typedef std::pair<int, int> Position;
typedef std::pair<int, int> Move;


class KnightsTour
{
public:
    KnightsTour(int givenSize); // EVC
    void printBoard(); // prints board
    void backtrackTour(Position startingPosition); // backtracking algorithm
    void warnsdorffsTour(Position startingPosition); // Warnsdorff's algorithm
    void initializeBoard(); // initializes board to all 0s
    void getBoard(vector<vector<int>>& board); // returns the board

private:
    vector<vector<int>> board; // the board
    int SIZE; // size of the board
    Move moves[8]; // possible moves a knight can make

    bool isValid(Position position); // determines of position is valid
    bool isOutOfBounds(Position position); // determines if position is in bounds
    int getDegree(Position position); // returns degree of a position
    bool backtrackTour(int count, Position position); // backtracking algorithm
};

#endif