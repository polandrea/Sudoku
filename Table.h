//
// Created by polandrea on 2023.04.03..
//

#ifndef SUDOKU_TABLE_H
#define SUDOKU_TABLE_H


#include <string>
#include <vector>

class Table {

    // Attributes
    int size;
    std::vector<int> content;
    std::vector<int> solution;
    std::vector<int> currentPosition;

    public:
    // Methods
    std::string drawTable ();
    void fillField ();
    bool validateTable ();
    void moveField ();


};


#endif //SUDOKU_TABLE_H
