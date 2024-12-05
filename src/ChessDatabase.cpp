#include "ChessDatabase.h"
#include "PGNParser.h"
#include <iostream>

void ChessDatabase::addGame(const ChessGame& game) {
    games.push_back(game);
}

void ChessDatabase::importFromPGN(const std::string& filePath) {
    std::vector<ChessGame> importedGames = PGNParser::parsePGN(filePath);
    games.insert(games.end(), importedGames.begin(), importedGames.end());
}

void ChessDatabase::printAllGames() const {
    for (const auto& game : games) {
        game.printGame();
    }
}
