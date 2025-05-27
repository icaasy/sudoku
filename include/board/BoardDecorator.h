#ifndef BOARDDECORATOR_H
#define BOARDDECORATOR_H

class BoardDecorator {
protected:
    HANDLE hConsole;
public:
    BoardDecorator() {
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    }
    virtual void drawBorder() = 0;
    virtual void drawCell(int value, bool isFixed) = 0;
    virtual void drawHeader() = 0;
    virtual ~BoardDecorator() {}
};

#endif //BOARDDECORATOR_H
