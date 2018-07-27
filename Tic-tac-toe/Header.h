#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <Windows.h>

using namespace std;

const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char NO_WIN = 'N';
const char TIE = 'T';

void inctruction();
char AskYesOrNo(string question);
int AskNumber(string question, int high, int low = 0);
char humanPiece();
char opponents(char piece);
void displayBoard(const vector<char>& board);
char winner(const vector<char>& board);
inline bool isLegal(const vector<char>& board, int move);
int humanMove(const vector<char>& board, char human);
int computerMove(vector<char> board, char computer);
void Win(char winner, char computer, char human);
bool restartGame();