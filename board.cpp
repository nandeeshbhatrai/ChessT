#include<vector>
#include "pieces.h"
#include "block.h"
#include "define.h"
#include "board.h"

#include<ncurses.h>

void clearScreen() {
    clear();
    refresh();
}

int main() {
    initscr();              // Start ncurses mode
    cbreak();               // Line buffering disabled
    noecho();               // Don't echo while we do getch
    timeout(100);           // Non-blocking getch, timeout in ms
    initColors();

    Board board;
    board.Set();

    while (true) {
        clearScreen();
        board.print();

        int ch = getch();
        if (ch == 'q' || ch == 'Q') {
            clearScreen();
            break;
        }
    }

    endwin();               // End ncurses mode
    return 0;
}