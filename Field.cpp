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

Field::Field(char set_value) {
    if (set_value == '0'){
        original = false;
    } else {
    original = true;}
    value = set_value;

}

Field::~Field() {

}
