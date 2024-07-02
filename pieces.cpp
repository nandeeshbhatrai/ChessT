#include "pieces.h"
#include <iostream>

int main() {
    Pieces pieces;
    std::vector<std::string> queen = pieces.queen();
    for(auto row : queen) {
        std::cout << row << std::endl;
    }
    return 0;
}
