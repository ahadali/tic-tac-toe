#include <iostream>

using namespace std;

const char human = 'X';
const char ai = 'O';

enum Player
{
	HUMAN, AI 
};

struct Move {
	int x;
	int y;
};

class Game {
	char board[3][3];

public:
	Game();

	void play();
	// Primary game driver, loops through turn-by-turn until there's
	// a winner or full game board (draw)

	void printBoard();
	// Prints the board

	bool checkWin(Player player);
	// Checks for a win

	bool gameOver();
	// Returns true if a winner has been found or there are no empty spaces

	void getHumanMove();
	// Takes in values from the input stream and places them on the board
	// if valid.  Expects input in coordinate notation, ex (1,3)

	Move minimax(char AIboard[3][3]);
	// Returns the best AI move's x, y coords via the minimax algorithm

	int maxSearch(char AIboard[3][3]);
	// minimax helper fn for finding the next move for human player, chooses
	// the move with the least possible score

	int score();
	// Function to score game board states based on their outcome
	// Returns 10 for human win, -10 for AI win, 0 for draw

	int minSearch(char AIboard[3][3]);
	// minimax helper fn for finding the next move for AI player, chooses the 
	// move with the least possible score
};
