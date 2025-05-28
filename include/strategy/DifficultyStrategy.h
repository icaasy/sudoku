#ifndef DIFFICULTYSTRATEGY_H
#define DIFFICULTYSTRATEGY_H

#include <string>

class DifficultyStrategy {
public:
    virtual int getEmptyCells() = 0;
    virtual std::string getName() = 0;
    virtual ~DifficultyStrategy() {}
};

#endif //DIFFICULTYSTRATEGY_H
