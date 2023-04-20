//
// Created by polandrea on 2023.04.05..
//

#include <iostream>
#include "Field.h"

char Field::getValue() {
    return value;
}

void Field::changeValue(char new_value) {
    if (original){
        std::cout << "It is a default field." << std::endl;
    } else {
        value = new_value;
    }
}

std::string Field::getColor(){
    return color;
}

void Field::changeColor(std::string new_color) {
    if (original){
        std::cout << "It is a default field." << std::endl;
    } else {
        color = new_color;
    }
}

Field::Field(char set_value) {
    if (set_value == '0'){
        original = false;
        value = ' ';
    } else {
    original = true;
    value = set_value;
    color = "\033[90m";
    }
}

Field::~Field() {

}

bool Field::isOriginal() {
    return original;
}
