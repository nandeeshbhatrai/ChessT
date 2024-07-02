#include<iostream>
#include<vector>
#include<string>
#include "pieces.h"
#include "block.h"
#include "define.h"

int main(){
    Pieces pieces;
    Block pawn(pieces.pawn(), 0);
    Block rook(pieces.rook(), 1);
    Block knight(pieces.knight(), 0);
    Block bishop(pieces.bishop(), 1);
    Block queen(pieces.queen(), 0);
    Block king(pieces.king(), 1);
    for(int i = 0; i < 4; ++i){
        std::cout << pawn.pixel[i] << rook.pixel[i] << knight.pixel[i] << bishop.pixel[i] << queen.pixel[i] << king.pixel[i] << std::endl;
    }
    ////
    for(int i = 0; i < 4; ++i){
        std::cout << (pawn.color == 0? RED_BG:WHITE_BG) << pawn.pixel[i] << (rook.color == 0? RED_BG:WHITE_BG) << rook.pixel[i]
         << (knight.color == 0? RED_BG:WHITE_BG) << knight.pixel[i] 
         << (bishop.color == 0? RED_BG:WHITE_BG) << bishop.pixel[i] 
         << (queen.color == 0? RED_BG:WHITE_BG) << queen.pixel[i] 
         << (king.color == 0? RED_BG:WHITE_BG) << king.pixel[i] << RESET << std::endl;
    }
    return 0;
}