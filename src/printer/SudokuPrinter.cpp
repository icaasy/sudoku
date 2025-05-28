#include "../../include/printer/SudokuPrinter.h"
#include <iostream>

SudokuPrinter::SudokuPrinter() : decorator(std::make_unique<FancyBoardDecorator>()),
                                theme(std::make_unique<OceanTheme>()) {
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

void SudokuPrinter::setDecorator(std::unique_ptr<BoardDecorator> newDecorator) {
    decorator = std::move(newDecorator);
}

void SudokuPrinter::setTheme(std::unique_ptr<ThemeFactory> newTheme) {
    theme = std::move(newTheme);
}

void SudokuPrinter::printBoard(const SudokuBoard& sudokuBoard) const {
    system("cls");
    drawTitle();
    decorator->drawHeader();

    for (int i = 0; i < SIZE1; i++) {
        SetConsoleTextAttribute(hConsole, 11);
        std::cout << " " << i + 1 << " ";

        if (i % 3 == 0 && i != 0) {
            decorator->drawBorder();
            std::cout << std::endl;
        }

        std::cout << "║";
        for (int j = 0; j < SIZE1; j++) {
            decorator->drawCell(sudokuBoard.getCell(i, j), sudokuBoard.isInitialCell(i, j));
            if ((j + 1) % 3 == 0) {
                std::cout << "║";
            } else {
                std::cout << "|";
            }
        }
        std::cout << std::endl;

        if (i == 8) {
            SetConsoleTextAttribute(hConsole, 11);
            std::cout << "  ╚═══╩═══╩═══╝ ╚═══╩═══╩═══╝ ╚═══╩═══╩═══╝" << std::endl;
        } else if ((i + 1) % 3 == 0) {
            decorator->drawBorder();
            std::cout << std::endl;
        }
    }
}

void SudokuPrinter::drawTitle() const {
    SetConsoleTextAttribute(hConsole, 13);
    std::cout << R"(
   _____       _       _
  / ____|     | |     | |
 | (___   __ _| | ___ | | ___   _ ___
  \___ \ / _` | |/ _ \| |/ / | | / __|
  ____) | (_| | | (_) |   <| |_| \__ \
 |_____/ \__,_|_|\___/|_|\_\\__,_|___/

                                      )" << std::endl << std::endl;
}

void SudokuPrinter::showTitle() const {
    system("cls");
    char sud[6] = {'S','U','D','O','K','U'};

    for (int i = 0; i < 6; i++) std::cout << "\n";
    std::cout << "\t\t";

    for (int i = 0; i < 6; i++) {
        std::cout << " ";
        Sleep(450);
        static CONSOLE_FONT_INFOEX fontex;
        fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        GetCurrentConsoleFontEx(hOut, 0, &fontex);
        fontex.FontWeight = 1200;
        fontex.dwFontSize.X = 60;
        fontex.dwFontSize.Y = 60;
        SetCurrentConsoleFontEx(hOut, NULL, &fontex);
        std::cout << sud[i];
    }

    Sleep(850);
    system("cls");

    static CONSOLE_FONT_INFOEX fontex;
    fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetCurrentConsoleFontEx(hOut, 0, &fontex);
    fontex.FontWeight = 500;
    fontex.dwFontSize.X = 30;
    fontex.dwFontSize.Y = 30;
    SetCurrentConsoleFontEx(hOut, NULL, &fontex);
}

void SudokuPrinter::printMenu() const {
    SetConsoleTextAttribute(hConsole, 14);
    std::cout << R"(
  +-----------------------------------------------------+
  |                   SUDOKU MENU                       |
  +-----------------------------------------------------+
  |  1. New Game                                        |
  |  2. Load Game                                       |
  |  3. Delete Saved Game                               |
  |  4. Change Theme                                    |
  |  5. Change Board Style                              |
  |  6. Exit                                            |
  +-----------------------------------------------------+
)" << std::endl;
    SetConsoleTextAttribute(hConsole, 15);
    std::cout << "  Enter your choice (1-6): ";
}

void SudokuPrinter::printThemeMenu() const {
    SetConsoleTextAttribute(hConsole, 14);
    std::cout << R"(
  +-----------------------------------------------------+
  |                   SELECT THEME                      |
  +-----------------------------------------------------+
  |  1. Light Theme                                     |
  |  2. Dark Theme                                      |
  |  3. Ocean Theme                                     |
  |  4. Back to Main Menu                               |
  +-----------------------------------------------------+
)" << std::endl;
    SetConsoleTextAttribute(hConsole, 15);
    std::cout << "  Enter your choice (1-4): ";
}

void SudokuPrinter::printStyleMenu() const {
    SetConsoleTextAttribute(hConsole, 14);
    std::cout << R"(
  +-----------------------------------------------------+
  |                 SELECT BOARD STYLE                  |
  +-----------------------------------------------------+
  |  1. Basic Style                                     |
  |  2. Fancy Style                                     |
  |  3. Back to Main Menu                               |
  +-----------------------------------------------------+
)" << std::endl;
    SetConsoleTextAttribute(hConsole, 15);
    std::cout << "  Enter your choice (1-3): ";
}

void SudokuPrinter::printWinMessage(int moves) const {
    SetConsoleTextAttribute(hConsole, 10);
    std::cout << R"(
  +-----------------------------------------------------+
  |              CONGRATULATIONS! YOU WON!              |
  +-----------------------------------------------------+
  |  You solved the Sudoku puzzle in )" << std::setw(3) << moves << R"( moves!        |
  +-----------------------------------------------------+
)" << std::endl;
    SetConsoleTextAttribute(hConsole, 15);
}