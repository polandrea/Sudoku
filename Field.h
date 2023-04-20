//
// Created by polandrea on 2023.04.05..
//

#ifndef SUDOKU_FIELD_H
#define SUDOKU_FIELD_H


class Field {

    // Attributes
    bool original;
    char value;
    std::string color;

public:
    // Methods
    Field(char set_value);
    ~Field();
    void changeValue(char new_value);
    char getValue();
    void changeColor(std::string new_color);
    std::string getColor();
    bool isOriginal();

};


#endif //SUDOKU_FIELD_H
