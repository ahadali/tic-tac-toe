#include "game.h"

Game::Game()
{
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			board[i][j]='-';
}

void Game::play()
{
	int turn=0;
	printBoard();
}

void Game::printBoard()
{
		cout<<"--------------------";
		
		for(int i=0; i<3; i++)
			for(int j=0; j<3; j++)
				cout<<"|"<<board[i][j]<<"|"<<endl;
		
		cout<<"\n--------------------\n";
}

bool Game::gameOver()
{
	if(checkWin());
}

bool Game::checkWin(Player player)
{
	char playerChar;

	if(player == HUMAN)
		playerChar = human;
	else
		player = ai;

	for(int i=0; i<3; i++)
	{
		// check rows
		if(board[i][0]==playerChar && board[i][1]==playerChar && board[i][2]==playerChar)
			return true;

		// check columns
		if(board[0][i]==playerChar && board[0][i]==playerChar && board[0][i]==playerChar)
			return true;
	}

	// check diagonals
	if(board[0][0]==playerChar && board[1][1]==playerChar && board[2][2])
		return true;
	if(board[0][2]==playerChar && board[1][1]==playerChar && board[2][0]==playerChar)
		return true;

	return false;
}