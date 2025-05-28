#include <Windows.h>
#include "../include/SudokuGame.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    srand(static_cast<unsigned int>(time(nullptr)));
    SudokuGame game;
    game.play();
    return 0;
}
