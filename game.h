#include <iostream>
using namespace std;

const char human='X';
const char ai='O';

enum Player
{
	HUMAN, AI
};

struct Move
{
	int x, y;
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

	Move minimax(char AIboard[3][3]);
	// returns the best AI move's x,y coordinates via minimax algo

	int maxSearch(char AIboard[3][3]);
	// minimax helper fx for finding the next move for human, chooses
	// the move with the max possible score

	int score();
	// function to score game board states based on their outcome.
	// Returns 10 for human win, -10 for AI win, 0 for draw

	int minSearch(char AIboard[3][3]);
	// minimax helper fx for finding the next move for AI, chooses
	// the move with the least possible score
};