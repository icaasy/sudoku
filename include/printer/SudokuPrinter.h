#ifndef SUDOKUPRINTER_H
#define SUDOKUPRINTER_H

#include <iomanip>
#include <memory>
#include <windows.h>
#include "../board/FancyBoardDecorator.h"
#include "../theme/OceanTheme.h"
#include "../../include/board/SudokuBoard.h"

class SudokuPrinter {
private:
    const int SIZE1 = 9;
    const int r = 9;
    const int c = 9;
    HANDLE hConsole;
    std::unique_ptr<BoardDecorator> decorator;
    std::unique_ptr<ThemeFactory> theme;

public:
    SudokuPrinter();
    void setDecorator(std::unique_ptr<BoardDecorator> newDecorator);
    void setTheme(std::unique_ptr<ThemeFactory> newTheme);
    void printBoard(const SudokuBoard& sudokuBoard) const;
    void drawTitle() const;
    void showTitle() const;
    void printMenu() const;
    void printThemeMenu() const;
    void printStyleMenu() const;
    void printWinMessage(int moves) const;
};

#endif // SUDOKUPRINTER_H