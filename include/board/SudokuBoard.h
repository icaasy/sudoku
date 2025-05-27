#ifndef SUDOKUBOARD_H
#define SUDOKUBOARD_H

const int SIZE1 = 9;
const int r = 9;
const int c = 9;

class SudokuBoard {
private:
    int board[SIZE1][SIZE1];
    int initialBoard[SIZE1][SIZE1] = { { 0, 5, 0, 2, 0, 0, 0, 9, 8 },
                                    { 0, 0, 9, 0, 0, 0, 0, 0, 0 },
                                    { 6, 4, 0, 0, 7, 0, 0, 0, 0 },
                                    { 3, 0, 1, 0, 0, 6, 0, 0, 7 },
                                    { 2, 0, 0, 3, 0, 0, 9, 0, 0 },
                                    { 0, 0, 5, 0, 0, 1, 3, 0, 6 },
                                    { 5, 0, 0, 0, 0, 2, 0, 1, 9 },
                                    { 0, 9, 0, 8, 0, 0, 0, 3, 0 },
                                    { 0, 0, 8, 0, 0, 0, 0, 0, 0 } };

public:
    SudokuBoard() {
        resetBoard();
        random_gen();
    }

    void resetBoard() {
        for (int i = 0; i < SIZE1; i++) {
            for (int j = 0; j < SIZE1; j++) {
                board[i][j] = initialBoard[i][j];
            }
        }
    }

    int getCell(int row, int col) const {
        return board[row][col];
    }

    void setCell(int row, int col, int value) {
        board[row][col] = value;
    }

    bool isInitialCell(int row, int col) const {
        return initialBoard[row][col] != 0;
    }

    void random_gen() {
        srand(time(0));
        for (int i = 0; i < SIZE1; i++) {
            for (int j = 0; j < SIZE1; j++) {
                if (initialBoard[i][j] != 0) {
                    int temp = rand() % 10;
                    while (checkColumn(j, temp) || checkRow(i, temp) || checkboxx(i, j, temp) || temp == 0) {
                        temp = rand() % 10;
                    }
                    initialBoard[i][j] = temp;
                    board[i][j] = temp;
                }
            }
        }
    }

    bool checkColumn(int col, int value) const {
        for (int row = 0; row < SIZE1; row++) {
            if (board[row][col] == value) {
                return true;
            }
        }
        return false;
    }

    bool checkRow(int row, int value) const {
        for (int col = 0; col < SIZE1; col++) {
            if (board[row][col] == value) {
                return true;
            }
        }
        return false;
    }

    bool checkboxx(int row, int col, int value) const {
        int boxStartRow = row - row % 3;
        int boxStartCol = col - col % 3;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[boxStartRow + i][boxStartCol + j] == value) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isSolved() const {
        for (int i = 0; i < SIZE1; i++) {
            for (int j = 0; j < SIZE1; j++) {
                if (board[i][j] == 0) {
                    return false;
                }
            }
        }
        return true;
    }

    bool canSolve(int row, int col) const {
        for (int i = 1; i <= SIZE1; i++) {
            if (!checkColumn(col, i) && !checkRow(row, i) && !checkboxx(row, col, i)) {
                return true;
            }
        }
        return false;
    }

    void initializeBlock(int row, int col) {
        int boxStartRow = (row / 3) * 3;
        int boxStartCol = (col / 3) * 3;

        for (int i = boxStartRow; i < boxStartRow + 3; i++) {
            for (int j = boxStartCol; j < boxStartCol + 3; j++) {
                board[i][j] = initialBoard[i][j];
            }
        }
    }
};

#endif //SUDOKUBOARD_H
