#ifndef GAMEOBSERVER_H
#define GAMEOBSERVER_H

class GameObserver {
public:
    virtual void onMoveMade(int moves) = 0;
    virtual void onGameSolved() = 0;
    virtual void onGameSaved() = 0;
    virtual void onGameLoaded() = 0;
    virtual ~GameObserver() {}
};


#endif //GAMEOBSERVER_H
