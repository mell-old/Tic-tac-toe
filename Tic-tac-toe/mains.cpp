#include "Header.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const int NumSquares = 9;
	vector<char> board(NumSquares, EMPTY);
	bool restart = true;
	while (restart)
	{
		inctruction();
		char human = humanPiece();
		char computer = opponents(human);
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
				board[move] = computer;
			}
			displayBoard(board);
			turn = opponents(turn);
		}
		Win(winner(board), computer, human);
		restart = restartGame();
	}
	return 0;
}

void inctruction()
{
	cout << "Добропожаловать в противостояние машины и человека: Крестики-нолики" << endl;
}

char AskYesOrNo(string question)
{
	char response;
	do
	{
		cout << question << "(y/n) : ";
		cin >> response;
	} while (response != 'y' && response != 'n');
	return response;
}

int AskNumber(string question, int high, int low)
{
	int number;
	do
	{
		cout << question << "(" << low << "-" << high << ") : ";
		cin >> number;
	} while ( number > high || number < low);
	return number;
}

char humanPiece()
{
	char go_first = AskYesOrNo("Ты хочешь ходить первым?");
		if (go_first == 'y')
		{
			cout << "Ладно...челове ходит первым...Тебе понадобится этот ход." << endl;
			return X;
		}
		else
		{
			cout << "Зря ты не взял себе этот ход человек...Я пойду первым." << endl;
			return O;
		}
}

char opponents(char piece)
{
	if (piece == 'Y')
		return O;
	else
		return X;
}

void displayBoard(const vector<char>& board)
{
	cout << "\n\t" << board[0] << "|" << board[1] << "|" << board[2];
	cout << "\n" << "      ----------";
	cout << "\n\t" << board[3] << "|" << board[4] << "|" << board[5];
	cout << "\n" << "      ----------";
	cout << "\n\t" << board[6] << "|" << board[7] << "|" << board[8] << endl;
}

char winner(const vector<char>& board)
{
	const int WIN_ROWS[8][3] =
	{ {0,1,2},{3,4,5}, {6,7,8}, {0,3,6}, {1,4,7}, {2,5,8}, {0,4,8}, {2,4,6} };
	const int TOTAL_ROWS = 8;
	//если одна из комбинаций не равна EMPTY, то победитель найден.
	for (int row = 0; row < TOTAL_ROWS; row++)
	{
		if ((board[WIN_ROWS[row][0]] != EMPTY) 
			&& (board[WIN_ROWS[row][0]] == board[WIN_ROWS[row][1]]) 
			&& (board[WIN_ROWS[row][1]] == board[WIN_ROWS[row][2]]))
		{
			return board[WIN_ROWS[row][0]];
		}
		
	}
	//победитель не определился проверяем на ничью
	if (count(board.begin(), board.end(), EMPTY) == 0)
		return TIE;
	//Нету победителя и ничьи, потому продолжаем
	return NO_WIN;
}

inline bool isLegal(const vector<char>& board, int move)
{
	return (board[move] == EMPTY);
}

int humanMove(const vector<char>& board, char human)
{
	int move = AskNumber("В какую клетку поставишь свою фигуру?" , (board.size() - 1));
	while (!isLegal(board, move))
	{
		cout << "Надо ставить фигуру в пустую клетку! Ты что правил не читал?" << endl;
		move = AskNumber("В какую клетку поставишь свою фигуру?", (board.size() - 1));
	}
	cout << "Хорошо..." << endl;
	return move;
}

int computerMove(vector<char> board, char computer)//пишем псевдоителект
{
	unsigned int move = 0;
	bool found = false;
	//если можно выиграть следующим ходом, сделать его
	while (!found && move < board.size())
	{
		if (isLegal(board, move))
		{
			board[move] = computer;
			found = winner(board) == computer;
			board[move] = EMPTY;
		}
		if (!found)
		{
			move++;
		}
	}
	if (!found)
	{
		move = 0;
		char human = opponents(computer);
		while (!found && move < board.size())
		{
			if (isLegal(board, move))
			{
				board[move] = human;
				found = winner(board) == human;
				board[move] = EMPTY;
			}
			if (!found)
			{
				move++;
			}
		}
	}
	if (!found)
	{
		move = 0;
		unsigned int i = 0;
		const int BestMove[] = { 4,0,2,6,8,1,3,5,7 };
		//выбыриаем лучшую свободную клетку
		while (!found && i < board.size())
		{
			move = BestMove[i];
			if (isLegal(board, move))
			{
				found = true;
			}

		}
	}
	cout << "Я делаю ход в клетку " << move;
	return move;
}

void Win(char winner, char computer, char human)
{
	
	if (winner == computer)
	{
		cout << winner << "-ки победили!" << endl;
		cout << "Видишь человек я умнее тебя!" << endl;
	}
	else if (winner == human)
	{
		cout << winner << "-ки победили!" << endl;
		cout << "Хм...а ты умнее чем я думал." << endl;
	}
	else
	{
		cout << "Ничья! Неплохо человек!" << endl;
	}
}

bool restartGame()
{
	char YesOrNo = AskYesOrNo("Еще партейку?");
	if (YesOrNo == 'y')
	{
		return true;
	}
	else
	{
		return false;
	}
}