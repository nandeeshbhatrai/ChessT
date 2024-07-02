#ifndef BLOCK_H
#define BLOCK_H

#include<vector>
#include<string>
#include "pieces.h"

struct Block{
    int color;  // 0 = white, 1 = black and -1 = empty
    std::vector<std::string> pixel;
    int size = 7;
    Block(std::vector<std::string> piece , int color = -1){
        this->color = color;
        pixel.resize(4 , std::string(size, ' '));
        for(int i = 0; i < 4; ++i){
            pixel[i][2] = piece[i][0];
            pixel[i][3] = piece[i][1];
            pixel[i][4] = piece[i][2];
        }
    }
};

#endif