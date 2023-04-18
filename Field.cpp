//
// Created by polandrea on 2023.04.05..
//

#include <iostream>
#include "Field.h"

int Field::getValue() {
    return value;
}

void Field::changeValue(int new_value) {
    if (original){
        std::cout << "It is a default field." << std::endl;
    } else {
        value = new_value;
    }
}

Field::Field(int set_value) {
    if (set_value == 0){
        original = false;
    } else {
    original = true;}
    value = set_value;

}

Field::~Field() {

}
