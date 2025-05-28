cmake_minimum_required(VERSION 3.31)
project(course work)

set(CMAKE_CXX_STANDARD 20)

add_executable(course work src/main.cpp
        include/theme/ThemeFactory.h
        include/theme/LightTheme.h
        include/theme/DarkTheme.h
        include/theme/OceanTheme.h
        include/observer/GameObserver.h
        include/observer/GameLogger.h
        include/strategy/DifficultyStrategy.h
        include/strategy/EasyDifficulty.h
        include/strategy/MediumDifficulty.h
        include/strategy/HardDifficulty.h
        include/board/BoardDecorator.h
        include/board/BasicBoardDecorator.h
        include/board/FancyBoardDecorator.h
        include/board/SudokuBoard.h
        include/printer/SudokuPrinter.h
        include/file/SudokuFileManager.h
        include/SudokuGame.h
        src/theme/DarkTheme.cpp
        src/theme/LightTheme.cpp
        src/theme/OceanTheme.cpp
        src/printer/SudokuPrinter.cpp
)
