#ifndef PIECES_H
#define PIECES_H

#include <vector>
#include <string>

class Pieces {
    public:
        std::vector<std::string> empty() {
            return {"    ",
                    "    ",
                    "    ",
                    "    ",};
        }
        
        std::vector<std::string> pawn() {
            return {" * ",
                    "***",
                    " * ",
                    "***",};
        }

        std::vector<std::string> rook() {
            return {"###",
                    " # ",
                    " # ",
                    "###",};
        }

        std::vector<std::string> knight() {
            return {"===",
                    "| V",
                    " \\ ",
                    "===",};
        }

        std::vector<std::string> bishop() {
            return {" / ",
                    "/ \\",
                    "\\ /",
                    " \\ ",};
        }

        std::vector<std::string> queen() {
            return {"M-M",
                    "===",
                    " # ",
                    "===",};
        }

        std::vector<std::string> king() {
            return {" | ",
                    "+++",
                    " | ",
                    "===",};
        }
};

#endif
