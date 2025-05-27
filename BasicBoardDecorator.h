#ifndef BASICBOARDDECORATOR_H
#define BASICBOARDDECORATOR_H
#include "BoardDecorator.h"
#include <iostream>

class BasicBoardDecorator : public BoardDecorator {
public:
    void drawBorder() override {
        SetConsoleTextAttribute(hConsole, 11);
        std::cout << "|-------|-------|-------|";
    }

    void drawCell(int value, bool isFixed) override {
        if (isFixed) {
            SetConsoleTextAttribute(hConsole, 14);
        } else {
            SetConsoleTextAttribute(hConsole, 10);
        }
        if (value == 0) {
            std::cout << " . ";
        } else {
            std:: cout << " " << value << " ";
        }
    }

    void drawHeader() override {
        SetConsoleTextAttribute(hConsole, 11);
        std::cout << "   1 2 3   4 5 6   7 8 9" << std::endl;
        std::cout << "  +-------+-------+-------+" << std::endl;
    }
};


#endif //BASICBOARDDECORATOR_H
