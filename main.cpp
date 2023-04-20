#include <iostream>
#include "Table.h"
#include <termios.h>
#include <stdio.h>
#define STDIN_FILENO 0

int main() {

        // Table gameTable(9, 3, {0,0}, {"080701030", "409000000", "050060418", "700009000", "800610500", "035000029", "060407090", "000008004", "020050070"}, {"286741935", "419385762", "357962418", "741529386", "892613547", "635874129", "568437291", "173298654", "924156873"});

        // Table gameTable(6, 4, {0,2}, {"450000", "300006", "040100", "001050", "200001", "000025"}, {"456213", "312546", "543162", "621354", "265431", "134625"} );

        Table gameTable(4, 4,{0, 1}, {"4010", "0200", "0030", "0001"}, {"4312", "1243", "2134", "3421"});

        while (true){

            gameTable.drawTable();
        // Black magic to prevent Linux from buffering keystrokes.
            struct termios t;
            tcgetattr(STDIN_FILENO, &t);
            t.c_lflag &= ~ICANON;
            tcsetattr(STDIN_FILENO, TCSANOW, &t);
        // Once the buffering is turned off, the rest is simple.
            char c,d,e;
            c = getchar();
            if (c == ' ') {
                gameTable.changeField();
            }
            if (c == '\n') {
                bool solved = gameTable.validateTable();
                if (solved) {
                    std::cout << "You solved the table!";
                    break;
                }
            }
            else if (c == 27) {
                std::cin >> d;
                std::cin >> e;
            gameTable.moveField(e);
            }
            system("clear");
        }
}

