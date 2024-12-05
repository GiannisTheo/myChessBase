#ifndef CHESSDATABASE_H
#define CHESSDATABASE_H

#include <vector>
#include "ChessGame.h"

class ChessDatabase {
private:
    std::vector<ChessGame> games;
public:
    void addGame(const ChessGame& game);
    void importFromPGN(const std::string& filePath);
    void printAllGames() const;
};

#endif