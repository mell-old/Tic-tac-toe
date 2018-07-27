#include "Header.h"

int main()
{
	const int NumSquares = 9;
	vector<char> board(NumSquares, EMPTY);
	inctruction();
	char human = humanPiece();
	char computer = opponets(human);
	char turn = X;
	displayBoard(board);

	while (winner(board) == NO_WIN)
	{
		int move;
		if (turn == human)
		{
			move = humanMove(board, human);
			board[move] = human;
		}
		else
		{
			move = computerMove(board, computer);
			board[move] = human;
		}
		displayBoard(board);
		turn = opponets(turn);
	}
	Win(winner(board), computer, human);
	return 0;
}