#ifndef MEDIUMDIFFICULTY_H
#define MEDIUMDIFFICULTY_H

#include "DifficultyStrategy.h"

class MediumDifficulty : public DifficultyStrategy {
public:
    int getEmptyCells() override { return 45; }
    std::string getName() override { return "Medium"; }
};

#endif //MEDIUMDIFFICULTY_H
