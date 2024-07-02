#ifndef BOARD_H
#define BOARD_H

#include<iostream>
#include<vector>
#include<ncurses.h>
#include "pieces.h"
#include "block.h"
#include "define.h"

void initColors() {
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_RED);   // RED_BG with WHITE_FG
    init_pair(2, COLOR_BLACK, COLOR_RED);   // RED_BG with BLACK_FG
    init_pair(3, COLOR_WHITE, COLOR_CYAN);  // SKY_BG with WHITE_FG
    init_pair(4, COLOR_BLACK, COLOR_CYAN);  // SKY_BG with BLACK_FG
}

class Board{
    private:
        static const std::string _default_;

    public:
        std::vector<std::vector<Block>> board;
        Board(){
            Pieces pieces;
            board.resize(8, std::vector<Block>(8, Block(pieces.empty(), -1)));
        }

        void Set(){
            // Black pieces
            Block b_pawn(Pieces().pawn() , 0);
            Block b_rook(Pieces().rook() , 0);
            Block b_knight(Pieces().knight() , 0);
            Block b_bishop(Pieces().bishop() , 0);
            Block b_queen(Pieces().queen() , 0);
            Block b_king(Pieces().king() , 0);

            // White pieces
            Block w_pawn(Pieces().pawn() , 1);
            Block w_rook(Pieces().rook() , 1);
            Block w_knight(Pieces().knight() , 1);
            Block w_bishop(Pieces().bishop() , 1);
            Block w_queen(Pieces().queen() , 1);
            Block w_king(Pieces().king() , 1);

            // Set black pieces
            board[0][0] = b_rook;
            board[0][1] = b_knight;
            board[0][2] = b_bishop;
            board[0][3] = b_queen;
            board[0][4] = b_king;
            board[0][5] = b_bishop;
            board[0][6] = b_knight;
            board[0][7] = b_rook;
            for(int i = 0; i < 8; ++i){
                board[1][i] = b_pawn;
            }

            // Set white pieces
            board[7][0] = w_rook;
            board[7][1] = w_knight;
            board[7][2] = w_bishop;
            board[7][3] = w_queen;
            board[7][4] = w_king;
            board[7][5] = w_bishop;
            board[7][6] = w_knight;
            board[7][7] = w_rook;
            for(int i = 0; i < 8; ++i){
                board[6][i] = w_pawn;
            }
        }

        void print(bool blink){
            for(int i = 0; i < 8; ++i) {
                for(int k = 0; k < 4; ++k) {
                    for(int j = 0; j < 8; ++j) {
                        int colorPair = ((i + j) & 1 ? (board[i][j].color == 1 ? 1 : 2) : (board[i][j].color == 1 ? 3 : 4));
                        attron(COLOR_PAIR(colorPair));
                        mvprintw(i * 4 + k, j * board[i][j].size, "%s", board[i][j].pixel[k].c_str());
                        attroff(COLOR_PAIR(colorPair));
                    }
                }
            }
            refresh();
            if(blink){
                mvprintw(33, 20, "Press 'q' to quit");
            }else{
                mvprintw(33, 20, "                 ");
            }
        }
};

const std::string Board::_default_ = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

#endif