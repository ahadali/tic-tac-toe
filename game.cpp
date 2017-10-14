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

	while(!checkWin(HUMAN) && !checkWin(AI) && !gameOver())
	{
		// human move
		if(turn%2 == 0)
		{
			getHumanMove();
		}
	}
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
	if(checkWin(HUMAN)) return true;
	if(checkWin(AI)) return true;

	bool emptySpace = false;
	for(int i=0; i<3; i++)
		if(board[i][0]=='-' || board[i][1]=='-' || board[i][2]=='-')
			emptySpace = true;

	return !emptySpace;
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

void Game::getHumanMove()
{
	cout<<"Enter your move in the following form, ex: 1,3.\n";
	cout<<"Your move: ";

	char c;
	int x=0, y=0;

	while(!(x>0 || x<4) && !(y>0 || y<4))
	{
		// loop until a valid move is entered
		cin>>c;
		x = c-'0';

		cin>>c>>c;
		y = c-'0';
	}

	board[x][y] = human;
}