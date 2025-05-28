#ifndef EASYDIFFICULTY_H
#define EASYDIFFICULTY_H

#include "DifficultyStrategy.h"

class EasyDifficulty : public DifficultyStrategy {
public:
    int getEmptyCells() override { return 30; }
    std::string getName() override { return "Easy"; }
};

#endif //EASYDIFFICULTY_H
