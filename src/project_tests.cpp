// Josh Schmitz
// project_tests.cpp
// April 2021
// Tests the knights tour algorithms in knights_tour.cpp

#include <iostream>
#include <gtest/gtest.h>
#include "knights_tour.h"

using namespace std;

// *****************************************************************
// HELPER FUNCTION FOR TESTING
// *****************************************************************

// determines whether or not the given position is in bounds
bool isInBounds(int boardSize, pair<int,int> position) {
    return (position.first >= 0 && position.first < boardSize &&
            position.second >= 0 && position.second < boardSize);
}

// determines whether or not a given tour is valid
bool isValid(vector<vector<int>>& board, int size) {
    pair<int,int> position;
    pair<int,int> moves[8];
    moves[0] = std::make_pair(-2, 1);   // up 2 right 1
    moves[1] = std::make_pair(-1, 2);   // up 1 right 2
    moves[2] = std::make_pair(1, 2);    // down 1 right 2
    moves[3] = std::make_pair(2, 1);    // down 2 right 1
    moves[4] = std::make_pair(2, -1);   // down 2 left 1
    moves[5] = std::make_pair(1, -2);   // down 1 left 2
    moves[6] = std::make_pair(-1, -2);  // up 1 left 2
    moves[7] = std::make_pair(-2, -1);  // up 2 left 1

    // find starting position
    for (size_t x = 0; x < size; ++x) {
        for (size_t y = 0; y < size; ++y) {
            if (board.at(x).at(y) == 1) {
                position = make_pair(x, y);
            }
        }
    }

    // checks to make sure all moves are valid
    for (size_t i = 2; i <= size * size; ++i) {
        bool found_i = false;
        for (Move move : moves) {
            Position tempPosition = make_pair(position.first + move.first,
                    position.second + move.second);
            if (isInBounds(size, tempPosition) && board.at(position.first +
                    move.first).at(position.second + move.second) == i) {
                found_i = true;
                position.first += move.first;
                position.second += move.second;
                break;
            }
        }
        if (!found_i) {
            return false;
        }
    }
    return true;
}

// prints the given board
void printBoard(vector<vector<int>>& board, int size) {
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            cout << setw(3) << board.at(i).at(j) << " ";
        }
        cout << endl;
    }
}

// resets board to blank ie all positions are 0
void initializeBoard(vector<vector<int>>& board, int size) {
    board.clear();
    for (size_t i = 0; i < size; ++i) {
        vector<int> newRow;
        for (size_t j = 0; j < size; ++j) {
            newRow.push_back(0);
        }
        board.push_back(newRow);
    }
}

// *****************************************************************
// TESTS
// *****************************************************************

// --- Meta Tests ---

// Used this test to visually confirm that getBoard() and printBoard() work
TEST(MetaTest, CheckPrint) {
    int size = 8;
    vector<vector<int>> board;
    initializeBoard(board, size);

    KnightsTour knightsTour(size);
    knightsTour.backtrackTour(make_pair(0, 0));
    knightsTour.printBoard();

    cout << endl;
    knightsTour.getBoard(board);
    printBoard(board, size);
}

// Used this test to manually confirm that isValid() works
TEST(MetaTest, CheckValidation) {
    int size = 8;
    vector<vector<int>> board;
    initializeBoard(board, size);

    KnightsTour knightsTour(8);
    knightsTour.backtrackTour(make_pair(0, 0));
    knightsTour.getBoard(board);

    ASSERT_TRUE(isValid(board, size));

    board.at(2).at(4) = 15;
    ASSERT_FALSE(isValid(board, size));
    
}

// --- Backtracking Algorithm Tests ---

// tests the backtracking algorithm on a size 8 board
TEST(BacktrackTests, RegularSize) {
    int size = 8;
    vector<vector<int>> board;
    initializeBoard(board, size);
    
    KnightsTour knightsTour(size);
    knightsTour.backtrackTour(make_pair(0, 0));
    knightsTour.getBoard(board);

    ASSERT_TRUE(isValid(board, size));
}

// tests the backtracking algorithm on a size 7 board
TEST(BacktrackTests, SmallSize) {
    int size = 7;
    vector<vector<int>> board;
    initializeBoard(board, size);

    KnightsTour knightsTour(size);
    knightsTour.backtrackTour(make_pair(0, 0));
    knightsTour.getBoard(board);

    ASSERT_TRUE(isValid(board, size));
}

// tests the backtracking algorithm for different initial positions
TEST(BacktrackTests, StartingPosition) {
    int size = 7;
    vector<vector<int>> board;
    initializeBoard(board, size);

    KnightsTour knightsTour(size);
    knightsTour.backtrackTour(make_pair(1, 1));
    knightsTour.getBoard(board);

    ASSERT_TRUE(isValid(board, size));
}

// --- Warnsdoff's Algorithm Tests ---

// tests Warndorff's algorithm on a size 8 board
TEST(WarnsdorffsTests, RegularSize) {
    int size = 8;
    vector<vector<int>> board;
    initializeBoard(board, size);
    
    KnightsTour knightsTour(size);
    knightsTour.warnsdorffsTour(make_pair(0, 0));
    knightsTour.getBoard(board);

    ASSERT_TRUE(isValid(board, size));
}

// tests Warndorff's algorithm on a size 6 board
TEST(WarnsdorffsTests, SmallSize) {
    int size = 5;
    vector<vector<int>> board;
    initializeBoard(board, size);

    KnightsTour knightsTour(size);
    knightsTour.warnsdorffsTour(make_pair(0, 0));
    knightsTour.getBoard(board);

    ASSERT_TRUE(isValid(board, size));
}

// tests Warndorff's algorithm on a size 16 board
TEST(WarnsdorffsTests, BiggerSize) {
    int size = 16;
    vector<vector<int>> board;
    initializeBoard(board, size);

    KnightsTour knightsTour(size);
    knightsTour.warnsdorffsTour(make_pair(0, 0));
    knightsTour.getBoard(board);

    ASSERT_TRUE(isValid(board, size));
}

// tests the backtracking algorithm for different initial positions
TEST(WarndorffsTests, StartingPosition) {
    int size = 8;
    vector<vector<int>> board;
    initializeBoard(board, size);

    KnightsTour knightsTour(size);
    knightsTour.backtrackTour(make_pair(7, 0));
    knightsTour.getBoard(board);

    ASSERT_TRUE(isValid(board, size));
}

// runs all the tests above
int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS(); 
}