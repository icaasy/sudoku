#ifndef HARDDIFFICULTY_H
#define HARDDIFFICULTY_H
#include "DifficultyStrategy.h"

class HardDifficulty : public DifficultyStrategy {
public:
    int getEmptyCells() override { return 60; }
    std::string getName() override { return "Hard"; }
};

#endif //HARDDIFFICULTY_H
