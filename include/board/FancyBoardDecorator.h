#ifndef FANCYBOARDDECORATOR_H
#define FANCYBOARDDECORATOR_H
#include "BoardDecorator.h"
#include <iostream>

class FancyBoardDecorator : public BoardDecorator {
public:
    void drawBorder() override {
        SetConsoleTextAttribute(hConsole, 13);
        std::cout << "-----------------------------------------------------------------";
    }

    void drawCell(int value, bool isFixed) override {
        if (isFixed) {
            SetConsoleTextAttribute(hConsole, 14 | BACKGROUND_BLUE);
        } else {
            SetConsoleTextAttribute(hConsole, 10 | BACKGROUND_INTENSITY);
        }
        if (value == 0) {
            std::cout << " · ";
        } else {
            std::cout << " " << value << " ";
        }
    }

    void drawHeader() override {
        SetConsoleTextAttribute(hConsole, 13);
        std::cout << "    1   2   3     4   5   6     7   8   9" <<std:: endl;
        std::cout << "  ╔═══╦═══╦═══╗ ╔═══╦═══╦═══╗ ╔═══╦═══╦═══╗" << std::endl;
    }
};

#endif //FANCYBOARDDECORATOR_H
