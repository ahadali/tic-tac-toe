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
		
		cout<<"--------------------";
}