//
// Created by polandrea on 2023.04.03..
//

#ifndef SUDOKU_TABLE_H
#define SUDOKU_TABLE_H


#include <string>
#include <vector>
#include "Field.h"

class Table {

    // Attributes
    int size;
    int dividingNum;
    std::vector<std::vector<Field>> content;
    std::vector<int> solution;
    std::vector<int> currentPosition;

    public:
    // Methods
    Table(int set_size, int set_dividingNum, std::vector<int>startingPosition, std::vector<std::string> set_content, std::vector<int> set_solution);
    ~Table();
    void drawTable();
    bool validateTable ();
    void moveField ();

};


#endif //SUDOKU_TABLE_H
