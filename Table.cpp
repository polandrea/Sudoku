//
// Created by polandrea on 2023.04.03..
//

#include <iostream>
#include <string>
#include "Table.h"


Table::Table(int set_size, int set_dividingNum, std::vector<int>startingPosition, std::vector<std::string> set_content, std::vector<int> set_solution) {
    size = set_size;
    dividingNum = set_dividingNum;
    solution = set_solution;
    currentPosition = startingPosition;

    // Every string from the input
    for (const auto &string: set_content) {
        std::vector<Field> fields;

        // Every character from the string
        for (int i = 0; i < string.length(); i++) {
           fields.push_back(Field(string[i]));
        }
        content.push_back(fields);
    }
}

Table::~Table() {
    //Delete all fields
}

void Table::changeField(){
    while(true) {
        char new_value;
        std::cout << "Type a number:";
        std::cin >> new_value;
        if ((new_value -'0') <= size && (new_value -'0') > 0) {
            content[currentPosition[0]][currentPosition[1]].changeValue(new_value);
            break;
        } else {
            std::cout << "\nWrong input!\n";
            continue;
        }
    }
}

bool Table::validateTable() {
    return false;
}

void Table::moveField(int key) {
    content[currentPosition[0]][currentPosition[1]].changeColor("\033[0m");
    if (key == 65) { currentPosition[0]--; }
    if (key == 66) { currentPosition[0]++; }
    if (key == 67) { currentPosition[1]++; }
    if (key == 68) { currentPosition[1]--; }

}

std::string topRow(int size, int dividingNum) {
    std::string result;
    if(size ==6){
        dividingNum=3;
    }
    for(int i=0; i <= size*4; i++) {
        if (i == 0) {
            result += "╔";
        } else if (i == size * 4) {
            result += "╗";
        } else if (i % 4 == 0 && i % (dividingNum*2) == 0) {
            result += "╦";
        } else {
            result += "═";
        }
    }
    return result;
}
std::string endRow(int size, int dividingNum) {
    std::string result;
    if(size ==6){
        dividingNum=3;
    }
    for(int i=0; i <= size*4; i++) {
        if (i == 0) {
            result += "╚";
        } else if (i == size * 4) {
            result += "╝";
        } else if (i % 4 == 0 && i % (dividingNum*2) == 0) {
            result += "╩";
        } else {
            result += "═";
        }
    }
    return result;
}
std::string lightWallRow(int size, int dividingNum){
    std::string result;
    if(size ==6){
        dividingNum=3;
    }
    for(int i=0; i <= size*4; i++) {
        if (i == 0 || i % 4 == 0 && i % (dividingNum*2) == 0) {
            result += "║";
        } else if (i == size * 4) {
            result += "║";
        } else if (i % 4 == 0 && i % (dividingNum*2) != 0) {
            result += "┼";
        } else {
            result += "─";
        }
    }
    return result;

}
std::string strongWallRow(int size, int dividingNum){
    std::string result;
    if(size ==6){
        dividingNum=3;
    }
    for(int i=0; i <= size*4; i++) {
        if (i == 0) {
            result += "╠";
        } else if (i == size * 4) {
            result += "╣";
        } else if (i % 4 == 0 && i % (dividingNum*2) == 0) {
            result += "╬";
        } else {
            result += "═";
        }
    }
    return result;
}
std::string middleRow(int size, int dividingNum, int row, std::vector<std::vector<Field>> contento){
    std::string result;
    int field = 0;
    if(size ==6){
        dividingNum=3;
    }
    for(int i=0; i <= size*4; i++) {
        if (i == 0 || i % 4 == 0 && i % (dividingNum*2) == 0) {
            result += "║";
        } else if (i == size * 4) {
            result += "║";
        } else if (i % 2 == 0 && i % 4 != 0){
            result += contento[row][field].getColor();
            result += contento[row][field].getValue();
            result += "[0m";
            field++;
        } else if (i % 4 == 0 && i % (dividingNum*2) != 0) {
            result += "│";
        }
        else {
            result += " ";
        }
    }
    return result;
}

void Table::drawTable() {
    content[currentPosition[0]][currentPosition[1]].changeColor("\033[47m");
    int row = 0;
    for (int i=0; i <= size*2; i++){
        if (i==0){
            std::cout << topRow(size, dividingNum) << std::endl;
        } else if (i == size*2){
            std::cout << endRow(size, dividingNum) << std::endl;
        } else if (i%2==0 && i%dividingNum!=0){
            std::cout << lightWallRow(size, dividingNum) << std::endl;
        } else if (i%2==0 && i%dividingNum==0){
            std::cout << strongWallRow(size, dividingNum) << std::endl;
        }  else {
            std::cout << middleRow(size, dividingNum, row, content) << std::endl;
            row++;
        }
    }

}

