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

Field::Field(bool is_original, int set_value) {
    original = is_original;
    value = set_value;

}
