#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

void printBoard(int board[9][3][3]) {
    for (int i = 0; i < 9; i++) {
        bool divisibleByThree = (i + 1) % 3 == 0;

        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                std::cout << board[i][j][k];

                if (k != 2){
                    std::cout << " | ";
                };
            };
            std::cout << " || ";
        };
        std::cout << std::endl << "--------------------------------------" << std::endl;

        if (divisibleByThree) {
            std::cout << std::endl;
        }
    };
}

void solve(int board[9][3][3]) {
    for (int row = 0; row < 9; row++) {                         // Loop through rows
        for (int block = 0; block < 3; block++) {               // Loop through a row
            for (int element = 0; element < 3; element++) {     // Loop through each element in a block
                if (board[row][block][element] == 0) {          // If the square is empty
                    std::vector<int> possible(9);
                    std::iota(std::begin(possible), std::end(possible), 1);

                    // Loop through possible, checking if it is in the block. If it is, it removes it
                    for (int i = 0; i < possible.size(); i++) {
                        int j = 0;
                        bool inBlock = false;
                        while (j < 3 && !inBlock) {
                            inBlock = std::find(std::begin(board[row][j]), std::end(board[row][j]), i+1) != std::end(board[row][j]);
                            j++;
                        };


                        if (inBlock) {
                            possible.erase(std::remove(possible.begin(), possible.end(), i), possible.end());
                        };
                    };

                    for (int i = 0; i < possible.size(); i++) { // NOLINT(*-loop-convert)
                        std::cout << possible[i] << ", ";
                    };
                    return;
                };
            };
        };
    };
}

int main() {
    int board[9][3][3] = {
            {{4, 9, 7}, {0, 3, 0}, {6, 0, 0}},
            {{1, 0, 6}, {5, 9, 0}, {7, 3, 0}},
            {{5, 0, 3}, {0, 0, 4}, {0, 1, 0}},

            {{9, 3, 1}, {0, 0, 0}, {0, 0, 0}},
            {{0, 0, 0}, {0, 1, 5}, {3, 4, 2}},
            {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}},

            {{0, 5, 4}, {8, 0, 1}, {9, 0, 6}},
            {{0, 1, 0}, {2, 0, 6}, {0, 7, 3}},
            {{0, 6, 0}, {0, 4, 9}, {8, 0, 0}}
    };

//     int guaranteed[][3] = {
//            {0, 0, 0}, {0, 0, 1}, {0, 0, 2}, {0, 2, 1}, {0, 2, 0},
//            {1, 0, 0}, {1, 0, 2}, {1, 1, 0}, {1, 1, 1}, {1, 2, 0}, {1, 2, 1},
//            {2, 0, 0}, {2, 0, 2}, {2, 1, 2}, {2, 2, 1},
//            {3, 0, 0}, {3, 0, 1}, {3, 0, 2},
//            {4, 1, 1}, {4, 1, 2},
//    };

    printBoard(board);
    solve(board);

    return 0;
}