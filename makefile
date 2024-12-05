CXX = g++
CXXFLAGS = -std=c++17 -Wall
SRC = src/main.cpp src/ChessGame.cpp src/PGNParser.cpp src/ChessDatabase.cpp
INC = include
OBJ = $(SRC:.cpp=.o)

all: chessdb

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I$(INC) -c $< -o $@

chessdb: $(OBJ)
	$(CXX) $(OBJ) -o chessdb

clean:
	rm -f $(OBJ) chessdb