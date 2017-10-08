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
	// Primary game driver, loops through turn-by-turn until there's
	// a winner or full game board (draw)
};