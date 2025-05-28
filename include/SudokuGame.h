#ifndef SUDOKUGAME_H
#define SUDOKUGAME_H
#include <vector>

#include "board/BasicBoardDecorator.h"
#include "theme/DarkTheme.h"
#include "observer/GameLogger.h"
#include "observer/GameObserver.h"
#include "theme/LightTheme.h"
#include "board/SudokuBoard.h"
#include "file/SudokuFileManager.h"
#include "printer/SudokuPrinter.h"

class SudokuGame {
private:
    SudokuBoard board;
    SudokuPrinter printer;
    SudokuFileManager fileManager;
    std::vector<std::unique_ptr<GameObserver>> observers;
    int moves;

    void notifyMoveMade() const {
        for (auto& observer : observers) {
            observer->onMoveMade(moves);
        }
    }

    void notifyGameSolved() const {
        for (auto& observer : observers) {
            observer->onGameSolved();
        }
    }

    void notifyGameSaved() const {
        for (auto& observer : observers) {
            observer->onGameSaved();
        }
    }

    void notifyGameLoaded() {
        for (auto& observer : observers) {
            observer->onGameLoaded();
        }
    }

public:
    SudokuGame() : moves(0) {
        observers.push_back(std::make_unique<GameLogger>());
    }

    void play() {
        while (true) {
            int option = showMainMenu();

            switch (option) {
            case 1: startNewGame(); break;
            case 2: loadGame(); break;
            case 3: deleteGame(); break;
            case 4: changeTheme(); break;
            case 5: changeBoardStyle(); break;
            case 6: return;
            }
        }
    }

private:
    int showMainMenu() {
        printer.showTitle();
        printer.printMenu();

        int option;
        std::cin >> option;

        while ((option < 1 || option > 6) || std::cin.fail()) {
            std::cout << "\n Invalid Input...Enter again (1-6):\n";
            std::cin.clear();
            std::cin.ignore(100, '\n');
            printer.printMenu();
            std::cin >> option;
        }

        return option;
    }

    void startNewGame() {
        board = SudokuBoard();
        moves = 0;
        printer.printBoard(board);
        handleGameInput();
    }

    void loadGame() {
        if (fileManager.loadGame(moves, board)) {
            notifyGameLoaded();
            system("pause");
            printer.printBoard(board);
            handleGameInput();
        }
    }

    void deleteGame() {
        fileManager.deleteSavedGame();
        int anss;
        std::cout << "\nEnter 0 to Go Back to Menu, Enter 1 to Exit...";
        std::cin >> anss;
        while (std::cin.fail() || (anss != 1 && anss != 0)) {
            std::cout << "\nInvalid Input.. Enter 0 to Go Back to Menu, Enter 1 to Exit...";
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cin >> anss;
        }
        if (anss == 0) {
            play();
        }
    }

    void changeTheme() {
        printer.printThemeMenu();

        int choice;
        std::cin >> choice;

        while (choice < 1 || choice > 4 || std::cin.fail()) {
            std::cout << "\nInvalid Input...Enter again (1-4):\n";
            std::cin.clear();
            std::cin.ignore(100, '\n');
            printer.printThemeMenu();
            std::cin >> choice;
        }

        switch (choice) {
        case 1:
            printer.setTheme(std::make_unique<LightTheme>());
            break;
        case 2:
            printer.setTheme(std::make_unique<DarkTheme>());
            break;
        case 3:
            printer.setTheme(std::make_unique<OceanTheme>());
            break;
        case 4:
            return;
        }

        std::cout << "Theme changed successfully!" << std::endl;
        system("pause");
    }

    void changeBoardStyle() {
        printer.printStyleMenu();

        int choice;
        std::cin >> choice;

        while (choice < 1 || choice > 3 || std::cin.fail()) {
            std::cout << "\nInvalid Input...Enter again (1-3):\n";
            std::cin.clear();
            std::cin.ignore(100, '\n');
            printer.printStyleMenu();
            std::cin >> choice;
        }

        switch (choice) {
        case 1:
            printer.setDecorator(std::make_unique<BasicBoardDecorator>());
            break;
        case 2:
            printer.setDecorator(std::make_unique<FancyBoardDecorator>());
            break;
        case 3:
            return;
        }

        std::cout << "Board style changed successfully!" << std::endl;
        system("pause");
    }

    void handleGameInput() {
        int row, col, value;

        while (!board.isSolved()) {
            std::cout << "\nMoves: " << moves << " \nFor Input...";
            std::cout << "\nEnter Row Number (1-9):";
            std::cin >> row;
            row--;
            while (row > 8 || row < 0 || std::cin.fail()) {
                std::cout << "Invalid Input...\n Enter Row Number Again (1-9): ";
                std::cin.clear();
                std::cin.ignore(100, '\n');
                std::cin >> row;
                row--;
            }

            std::cout << "\nEnter Column Number (1-9):";
            std::cin >> col;
            col--;
            while (col > 8 || col < 0 || std::cin.fail()) {
                std::cout << "Invalid Input...\n Enter Column Number Again (1-9): ";
                std::cin.clear();
                std::cin.ignore(100, '\n');
                std::cin >> col;
                col--;
            }

            if (!board.isInitialCell(row, col)) {
                if (board.canSolve(row, col)) {
                    std::cout << "\nEnter Value for [" << row + 1 << "][" << col + 1 << "] (1-9):";
                    std::cin >> value;
                    moves++;
                    notifyMoveMade();
                    while (board.checkColumn(col, value) || board.checkRow(row, value) ||
                        board.checkboxx(row, col, value) || value > 9 || value <= 0) {
                       std:: cout << "\nMoves: " << moves;
                        std::cout << "\nInvalid input...\nEnter Value for [" << row + 1 << "][" << col + 1 << "] (1-9):";
                        std::cin.clear();
                       std:: cin.ignore(100, '\n');
                        std::cin >> value;
                        moves++;
                        notifyMoveMade();
                    }
                    board.setCell(row, col, value);
                    printer.printBoard(board);
                }
                else {
                    int choice;
                    std::cout << "\nThis Current form of Sudoku Table is impossible to solve...\n Enter 1 to reset the current block, enter 2 to continue: ";
                    std::cin >> choice;
                    while (choice != 1 && choice != 2) {
                       std:: cout << "Invalid Input...\n Enter 1 to reset this block, enter 2 to continue:";
                       std:: cin >> choice;
                    }

                    if (choice == 1) {
                        board.initializeBlock(row, col);
                        printer.printBoard(board);
                    }
                    else {
                        printer.printBoard(board);
                    }
                }
            }
            else {
                std::cout << "\nIndex is Non Editable...";
            }

            int ans;
            std::cout << "\nEnter -1 to Save or Enter 0 to Continue...";
            std::cin >> ans;
            while ((ans != -1 && ans != 0) || std::cin.fail()) {
               std::cout << "\n Invalid input...\n Enter Again:";
                std::cin.clear();
                std::cin.ignore(100, '\n');
                std::cin >> ans;
            }

            if (ans == -1) {
                if (fileManager.saveGame(moves, board)) {
                    notifyGameSaved();
                    break;
                }
            }
            else {
                printer.printBoard(board);
            }
        }

        if (board.isSolved()) {
            printer.printWinMessage(moves);
            notifyGameSolved();
        }
        std::cout << "\n Press any key to return to main menu...";
        system("pause > nul");
    }
};


#endif //SUDOKUGAME_H
