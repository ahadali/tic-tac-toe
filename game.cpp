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
			
			if(checkWin(HUMAN)) cout<<"Human Player wins!" << endl;
			turn++;
			printBoard();
		}
		else
		{
			cout<<"\nComputer Player move:\n";

			Move AImove = minimax(board);

			board[AImove.x][AImove.y] = ai;

			if(checkWin(AI)) cout<<"Computer Player Wins\n";

			turn++;
			printBoard();
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

Move Game::minimax(char AIboard[3][3])
{
	int bestMoveScore = 100;
	Move bestMove;

	for(int i=0; i<3; i++)
		for(j=0; j<3; j++)
		{
			if(AIboard[i][j] == '-')
			{
				AIboard[i][j] = ai;

				int tempMoveScore = maxSearch(AIboard);

				if(tempMoveScore <= bestMoveScore)
				{
					bestMoveScore = tempMoveScore;
					bestMove.x = i;
					bestMove.y = j;
				}

				AIboard[i][j] = '-';
			}
		}

	return bestMove;
}

int Game::maxSearch(char AIboard[3][3])
{
	if(gameOver()) return score();
	
	int bestMoveScore = -1000;
	Move bestMove;

	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
		{
			if(AIboard[i][j] == '-')
				AIboard[i][j] = human;

			int tempMoveScore = minSearch(AIboard);

			if(tempMoveScore >= bestMoveScore)
			{
				bestMoveScore = tempMoveScore;
				bestMove.x = i;
				bestMove.y = j;
			}

			AIboard[i][j] = '-';
		}

	return bestMoveScore;
}

int Game::score()
{
	if(checkWin(HUMAN)) return 10;
	if(checkWin(AI)) return -10;
	return 0;	// draw
}

int Game::minSearch(char AIboard[3][3])
{
	if(gameOver()) return score();

	int bestMoveScore = 1000;
	Move bestMove;

	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
		{
			if(AIboard[i][j] == '-')
			{
				AIboard[i][j] = ai;

				int tempMoveScore = maxSearch(AIboard);

				if(tempMoveScore <= bestMoveScore)
				{
					bestMoveScore = tempMoveScore;
					bestMove.x = i;
					bestMove.y = j;
				}

				AIboard[i][j] = '-';
			}
		}

	return bestMoveScore;
}
