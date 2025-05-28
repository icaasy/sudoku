#ifndef GAMELOGGER_H
#define GAMELOGGER_H

#include "GameObserver.h"
#include <iostream>
#include <fstream>
#include <ctime>

class GameLogger : public GameObserver {
public:
    void onMoveMade(int moves) override {
        std::ofstream logFile("sudoku_log.txt", std::ios::app);
        if (logFile.is_open()) {
            time_t now = time(0);
            char* dt = ctime(&now);
            logFile << "[" << dt << "] Move made. Total moves: " << moves << std::endl;
            logFile.close();
        }
    }

    void onGameSolved() override {
        std::ofstream logFile("sudoku_log.txt", std::ios::app);
        if (logFile.is_open()) {
            time_t now = time(0);
            char* dt = ctime(&now);
            logFile << "[" << dt << "] Game solved!" << std::endl;
            logFile.close();
        }
    }

    void onGameSaved() override {
        std::ofstream logFile("sudoku_log.txt", std::ios::app);
        if (logFile.is_open()) {
            time_t now = time(0);
            char* dt = ctime(&now);
            logFile << "[" << dt << "] Game saved." << std::endl;
            logFile.close();
        }
    }

    void onGameLoaded() override {
        std::ofstream logFile("sudoku_log.txt", std::ios::app);
        if (logFile.is_open()) {
            time_t now = time(0);
            char* dt = ctime(&now);
            logFile << "[" << dt << "] Game loaded." << std::endl;
            logFile.close();
        }
    }
};

#endif //GAMELOGGER_H
