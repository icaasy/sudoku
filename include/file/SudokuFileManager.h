#ifndef SUDOKUFILEMANAGER_H
#define SUDOKUFILEMANAGER_H

#include <iostream>


class SudokuFileManager {
private:
    bool isFileEmpty(std::ifstream& pFile) const {
        return pFile.peek() == std::ifstream::traits_type::eof();
    }

public:
    bool saveGame(int moves, const SudokuBoard& sudokuBoard) const {
        std::ofstream file1, file2, file3;
        std::ifstream file1_1, file2_2, file3_3;

        file1_1.open("game1.txt");
        file2_2.open("game2.txt");
        file3_3.open("game3.txt");

        bool flag1 = isFileEmpty(file1_1);
        bool flag2 = isFileEmpty(file2_2);
        bool flag3 = isFileEmpty(file3_3);

        file1_1.close();
        file2_2.close();
        file3_3.close();

        if (flag1) {
            file1.open("game1.txt");
            file1 << moves << std::endl;
            for (int i = 0; i < SIZE1; i++) {
                for (int j = 0; j < SIZE1; j++) {
                    file1 << sudokuBoard.getCell(i, j) << " ";
                }
                file1 << std::endl;
            }
            std::cout << "\nGame saved in file1...";
            file1.close();
            return true;
        }
        else if (flag2) {
            file2.open("game2.txt");
            file2 << moves << std::endl;
            for (int i = 0; i < SIZE1; i++) {
                for (int j = 0; j < SIZE1; j++) {
                    file2 << sudokuBoard.getCell(i, j) << " ";
                }
                file2 << std::endl;
            }
            std::cout << "\nGame saved in file2...";
            file2.close();
            return true;
        }
        else if (flag3) {
            file3.open("game3.txt");
            file3 << moves << std::endl;
            for (int i = 0; i < SIZE1; i++) {
                for (int j = 0; j < SIZE1; j++) {
                    file3 << sudokuBoard.getCell(i, j) << " ";
                }
                file3 << std::endl;
            }
            std::cout << "\nGame saved in file3...";
            file3.close();
            return true;
        }
        else {
            std::cout << "\nGame cannot be saved... \nAtleast 1 File Must be Emptied Before Any New Game gets Saved.." << std::endl;
            return false;
        }
    }

    bool loadGame(int& moves, SudokuBoard& sudokuBoard) const {
        int ans;
       std:: ifstream File1, File2, File3;

        File1.open("game1.txt");
        File2.open("game2.txt");
        File3.open("game3.txt");

        bool flag1 = !isFileEmpty(File1);
        bool flag2 = !isFileEmpty(File2);
        bool flag3 = !isFileEmpty(File3);

        File1.close();
        File2.close();
        File3.close();

        if (flag1 || flag2 || flag3) {
            std::cout << "\nLoad Game...";
            if (flag1) std::cout << "\n1-File1";
            if (flag2) std::cout << "\n2-File2";
            if (flag3) std::cout << "\n3-File3";

            while (true) {
                std::cout << "\nEnter file num to load: ";
                std::cin >> ans;
                while (std::cin.fail()) {
                    std::cout << "\nInvalid Input...";
                    std::cin.clear();
                    std::cin.ignore(100, '\n');
                    std::cin >> ans;
                }

                switch (ans) {
                case 1:
                    if (flag1) {
                        File1.open("game1.txt");
                        File1 >> moves;
                        for (int i = 0; i < SIZE1; i++) {
                            for (int j = 0; j < SIZE1; j++) {
                                int value;
                                File1 >> value;
                                sudokuBoard.setCell(i, j, value);
                            }
                        }
                        File1.close();
                        return true;
                    }
                    break;
                case 2:
                    if (flag2) {
                        File2.open("game2.txt");
                        File2 >> moves;
                        for (int i = 0; i < SIZE1; i++) {
                            for (int j = 0; j < SIZE1; j++) {
                                int value;
                                File2 >> value;
                                sudokuBoard.setCell(i, j, value);
                            }
                        }
                        File2.close();
                        return true;
                    }
                    break;
                case 3:
                    if (flag3) {
                        File3.open("game3.txt");
                        File3 >> moves;
                        for (int i = 0; i < SIZE1; i++) {
                            for (int j = 0; j < SIZE1; j++) {
                                int value;
                                File3 >> value;
                                sudokuBoard.setCell(i, j, value);
                            }
                        }
                        File3.close();
                        return true;
                    }
                    break;
                default:
                    std::cout << "\n Invalid Choice...";
                    continue;
                }
                std::cout << "\n File Does not Exists";
            }
        }
        else {
            std::cout << "\nNo File Exists...";
            return false;
        }
    }

    void deleteSavedGame() const {
        int ans;
        std::ifstream File1, File2, File3;
        std::ofstream File1_1, File2_2, File3_3;

        File1.open("game1.txt");
        File2.open("game2.txt");
        File3.open("game3.txt");

        bool flag1 = !isFileEmpty(File1);
        bool flag2 = !isFileEmpty(File2);
        bool flag3 = !isFileEmpty(File3);

        File1.close();
        File2.close();
        File3.close();

        if (flag1 || flag2 || flag3) {
            std::cout << "\nDelete Game...";
            if (flag1) std::cout << "\n1-File1";
            if (flag2) std::cout << "\n2-File2";
            if (flag3) std::cout << "\n3-File3";

            while (true) {
                std::cout << "\nEnter file num to Delete: ";
                std::cin >> ans;
                while (std::cin.fail()) {
                    std::cout << "\nInvalid Input...";
                    std::cin.clear();
                    std::cin.ignore(100, '\n');
                    std::cin >> ans;
                }

                switch (ans) {
                case 1:
                    if (flag1) {
                        File1_1.open("game1.txt", std::ios::out | std::ios::trunc);
                        File1_1.close();
                        std::cout << "\nGame Stored in File-1 deleted Successfully";
                        return;
                    }
                    break;
                case 2:
                    if (flag2) {
                        File2_2.open("game2.txt", std::ios::out | std::ios::trunc);
                        File2_2.close();
                        std::cout << "\nGame Stored in File-2 deleted Successfully";
                        return;
                    }
                    break;
                case 3:
                    if (flag3) {
                        File3_3.open("game3.txt", std::ios::out | std::ios::trunc);
                        File3_3.close();
                        std::cout << "\nGame Stored in File-3 deleted Successfully";
                        return;
                    }
                    break;
                default:
                    std::cout << "\n Invalid Choice...";
                    continue;
                }
                std::cout << "\n File Does not Exists";
            }
        }
        else {
           std:: cout << "\nNo File Exists..";
        }
    }
};


#endif //SUDOKUFILEMANAGER_H
