#include "PGNParser.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <regex>

// Helper function to replace starts_with
bool startsWith(const std::string& str, const std::string& prefix) {
    return str.rfind(prefix, 0) == 0;
}

std::vector<ChessGame> PGNParser::parsePGN(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
        return {};
    }

    std::vector<ChessGame> games;
    std::string line, white, black, result, event, date, opening;
    std::string moves;  // A single string to store all the moves

    //bool collectingMoves = false;

    while (std::getline(file, line)) {
        // Check for metadata fields
        if (startsWith(line, "[White ")) white = line.substr(8, line.length() - 10);
        else if (startsWith(line, "[Black ")) black = line.substr(8, line.length() - 10);
        else if (startsWith(line, "[Result ")) result = line.substr(9, line.length() - 11);
        else if (startsWith(line, "[Event ")) event = line.substr(8, line.length() - 10);
        else if (startsWith(line, "[Date ")) date = line.substr(7, line.length() - 9);
        else if (startsWith(line, "[Opening ")) opening = line.substr(10, line.length() - 12);
        ///else if (startsWith(line, "[Variation ")) variation = line.substr(12, line.length() - 14);
        else if (startsWith(line,"1.")){
            moves = line;
            games.emplace_back(white, black, result, event, date, opening, moves);
            white.clear(); black.clear(); result.clear(); event.clear(); date.clear(); opening.clear();
            moves.clear();  // Clear the moves for the next game
        }

        // // Start collecting moves after metadata
        // if (line.empty() && !white.empty() && !black.empty() && !result.empty()) {
        //     collectingMoves = true;
        // }

        // // Collect the moves
        // if (collectingMoves) {
        //     // Concatenate moves into a single string
        //     moves += line + " ";  // Add each line of moves to the `moves` string with a space

        //     // If we encounter an empty line after collecting moves, store the game
        //     if (line.empty()) {
        //         games.emplace_back(white, black, result, event, date, opening, moves);
        //         white.clear(); black.clear(); result.clear(); event.clear(); date.clear(); opening.clear();
        //         moves.clear();  // Clear the moves for the next game
        //         collectingMoves = false;
        //     }
        // }
    }

    file.close();
    return games;
}