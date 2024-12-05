#include "ChessDatabase.h"
#include <iostream>

int main() {
    ChessDatabase db;

    std::string filePath;
    std::cout << "Enter the path to the PGN file: ";
    std::cin >> filePath;

    db.importFromPGN(filePath);
    db.printAllGames();

    return 0;
}
