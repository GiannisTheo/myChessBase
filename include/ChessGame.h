#ifndef CHESSGAME_H
#define CHESSGAME_H

#include <string>

class ChessGame {
public:
    std::string whitePlayer;
    std::string blackPlayer;
    std::string result;
    std::string event;
    std::string date;
    std::string opening;
    std::string moves;  // Stores the moves of the game
    //std::string variation;

    ChessGame(const std::string& white, const std::string& black, const std::string& res, 
              const std::string& evt, const std::string& d, const std::string& open, const std::string& mv);

    void printGame() const;
};

#endif
