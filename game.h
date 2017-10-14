#include <iostream>
using namespace std;

const char human='X';
const char ai='O';

enum Player
{
	HUMAN, AI;
};

class Game {
	char board[3][3];

public:
	Game();
	// initializes the board with _

	void play();
	// Primary game driver, loops through turn-by-turn until there's a
	// winner or full game board (draw)

	void printBoard();
	// prints the board

	bool gameOver();
	// returns true if winner has been found or there are no empty spaces

	bool checkWin(Player player);
	// checks for a win

	void getHumanMove();
	// takes in values from the input stream and places them on the board
	// if valid. Expects input in given notation, (1,3)
};