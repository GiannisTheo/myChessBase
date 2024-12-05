#include "ChessGame.h"
#include <iostream>

ChessGame::ChessGame(const std::string& white, const std::string& black, const std::string& res, 
                     const std::string& evt, const std::string& d, const std::string& open, const std::string& mv)
    : whitePlayer(white), blackPlayer(black), result(res), event(evt), date(d), opening(open), moves(mv) {}

void ChessGame::printGame() const {
    std::cout << "White: " << whitePlayer << ", Black: " << blackPlayer
              << ", Result: " << result << ", Event: " << event 
              << ", Date: " << date << ", Opening: " << opening 
              << std::endl 
              << "Moves: " << moves 
              << std::endl;
}
