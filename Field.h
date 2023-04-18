//
// Created by polandrea on 2023.04.05..
//

#ifndef SUDOKU_FIELD_H
#define SUDOKU_FIELD_H


class Field {

    // Attributes
    bool original;
    int value;

public:
    // Methods
    Field(int set_value);
    ~Field();
    void changeValue(int new_value);
    int getValue();

};


#endif //SUDOKU_FIELD_H
