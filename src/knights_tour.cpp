// Josh Schmitz
// knights_tour.cpp
// April 2021
// Solves the knights tour problem using Warnsdorff's algorithm and a
//  backtracking approach.

#include "knights_tour.h"

// EVC - constructs board and sets moves array
KnightsTour::KnightsTour(int givenSize) {
    this->SIZE = givenSize;

    initializeBoard();
    
    moves[0] = std::make_pair(-2, 1);   // up 2 right 1
    moves[1] = std::make_pair(-1, 2);   // up 1 right 2
    moves[2] = std::make_pair(1, 2);    // down 1 right 2
    moves[3] = std::make_pair(2, 1);    // down 2 right 1
    moves[4] = std::make_pair(2, -1);   // down 2 left 1
    moves[5] = std::make_pair(1, -2);   // down 1 left 2
    moves[6] = std::make_pair(-1, -2);  // up 1 left 2
    moves[7] = std::make_pair(-2, -1);  // up 2 left 1
}

// prints the board
void KnightsTour::printBoard() {
    for (size_t i = 0; i < SIZE; ++i) {
        for (size_t j = 0; j < SIZE; ++j) {
            cout << setw(3) << board.at(i).at(j) << " ";
        }
        cout << endl;
    }
}

// creates new board
void KnightsTour::initializeBoard() {
    for (size_t i = 0; i < SIZE; ++i) {
        vector<int> newRow;
        for (size_t j = 0; j < SIZE; ++j) {
            newRow.push_back(0);
        }
        board.push_back(newRow);
    }
}

// returns the current board
void KnightsTour::getBoard(vector<vector<int>>& outputBoard) {
    for (size_t i = 0; i < SIZE; ++i) {
        for (size_t j = 0; j < SIZE; ++j) {
            outputBoard.at(i).at(j) = board.at(i).at(j);
        }
    }
}

// checks to see if position is out of bounds
bool KnightsTour::isOutOfBounds(Position position) {
    return !(position.first >= 0 && position.first < SIZE
            && position.second >= 0 && position.second < SIZE);
}

// checks to see if position is valid - ie in bounds and not filled
bool KnightsTour::isValid(Position position) {
    if (isOutOfBounds(position)) {
        return false;
    }
    if (board.at(position.first).at(position.second) != 0) {
        return false;
    }
    return true;
}

// solves knights tour using a backtracking algorithm
void KnightsTour::backtrackTour(Position startingPosition) {
    backtrackTour(1, startingPosition);
}

// recursive helper function to solve knights tour via backtracking
bool KnightsTour::backtrackTour(int count, Position position) {
    board.at(position.first).at(position.second) = count;

    if (count == SIZE * SIZE) {
        return true;
    }

    Position nextPosition;

    for (size_t i = 0; i < SIZE; ++i) {
        nextPosition.first = position.first + moves[i].first;
        nextPosition.second = position.second + moves[i].second;

        // check if nextPosition is valid
        if (!isValid(nextPosition)) {
            continue;
        }

        if (backtrackTour(count + 1, nextPosition)) {
            return true;
        }
    }

    // no valid tours from this position
    board.at(position.first).at(position.second) = 0;

    return false;
}

// returns the degree of the given position - used for Warnsdorffs algorithm
int KnightsTour::getDegree(Position position) {
    int degree = 0;
    for (Move move : moves) {
        Position pos(position.first + move.first, position.second + move.second);

        if (isValid(pos)) {
            degree++;
        }
    }
    return degree;
}

// solves knights tour using Warndorff's algorithm
void KnightsTour::warnsdorffsTour(Position startingPosition) {
    Position position = startingPosition;

    for (size_t i = 1; i <= SIZE * SIZE; ++i) {
        board.at(position.first).at(position.second) = i;

        // get list of possible positions
        list<Position> possiblePositions;
        for (Move move : moves) {
            Position nextPosition(position.first + move.first,
                    position.second + move.second);
            if (isValid(nextPosition)) {
                possiblePositions.push_back(nextPosition);
            }
        }

        // get position with highest degree
        Position minDegreePosition = possiblePositions.front();
        int minDegree = getDegree(minDegreePosition);
        for (Position pos : possiblePositions) {
            if (getDegree(pos) < minDegree) {
                minDegree = getDegree(pos);
                minDegreePosition = pos;
            }
        }

        position = minDegreePosition;
    }
}