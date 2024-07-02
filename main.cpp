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

    bool blink = true;

    while (true) {
        clearScreen();
        blink = !blink;
        board.print(blink);

        int ch = getch();
        if (ch == 'q' || ch == 'Q') {
            clearScreen();
            break;
        }
    }

    endwin();               // End ncurses mode
    return 0;
}