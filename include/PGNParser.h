#ifndef PGNPARSER_H
#define PGNPARSER_H

#include <string>
#include <vector>
#include "ChessGame.h"

class PGNParser {
public:
    static std::vector<ChessGame> parsePGN(const std::string& filePath);
};

#endif
