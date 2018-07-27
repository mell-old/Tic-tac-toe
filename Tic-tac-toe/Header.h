#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char NO_WIN = 'N';
const char TIE = 'T';

void inctruction();
char AskTesOrNo(string question);
char AsskNumber(string question);
char humanPiece();
char opponets(char piece);
void displayBoard(vector<char>& board);
char winner(vector<char>& board);
bool isLegal(vector<char>& board, int move);
int humanMove(vector<char>& board, char human);
int computerMove(vector<char> board, char computer);
void Win(char winner, char computer, char human);