#include <iostream>
#include <vector>

using namespace std;

void printBoard (vector<vector<char>> v,int n,int m){

	cout << "   ";
	for (int i = 0; i < m; i++) { // The loop that use to print out the english character row.
		cout << (char)('A' + i) << " ";
	}
	cout << endl;
	for (int i = 0; i < v.size(); i++)
	{
		if (i < 10)
			cout << i << "  ";
		else
			cout << i << " ";

		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
	cout << endl;
}
}

vector<vector<char>> createBoard(int m, int n) {
	
	vector<vector<char>>board;
			for (int j = 0; j < m; j++) {
				vector<char> row;
				for (int i = 0; i < n; i++)
					row.push_back('.');
				board.push_back(row);
			}
			return board;

}

bool isValid(vector<vector<char>>board,	int x, int y) {
	vector<char> row = board[0];
	if ((y < board.size()) && (x < row.size()) && (x >= 0) && (y >= 0) && (board[y][x] == '.'))
		return true;
	else
	{
		cout << "Input is incorrect\n";
		return false;
	}


}

char checkTheWinner(vector<vector<char>>board) {
	vector<char> row = board[0];
	for (int x=0; x < row.size()-4; x++) {
		for (int y = 0; y < (board.size() - 4);y++){
			if (board[x][y] != '.') {

				if (board[x][y] == 'o' && board[x + 1][y] == 'o' && board[x + 2][y] == 'o' && board[x + 3][y] == 'o' && board[x + 4][y] == 'o') {
					
					return 'O';
				}
				else if (board[x][y] == 'o' && board[x + 1][y + 1] == 'o' && board[x + 2][y + 2] == 'o' && board[x + 3][y + 3] == 'o' && board[x + 4][y + 4] == 'o') {
					
					return 'O';
				}
				else if (board[x][y] == 'o' && board[x][y + 1] == 'o' && board[x][y + 2] == 'o' && board[x][y + 3] == 'o' && board[x][y + 4] == 'o') {
					
					return 'O';
				}
				if (board[x][y] == 'x' && board[x + 1][y] == 'x' && board[x + 2][y] == 'x' && board[x + 3][y] == 'x' && board[x + 4][y] == 'x') {

					return 'X';
				}
				else if (board[x][y] == 'x' && board[x + 1][y + 1] == 'x' && board[x + 2][y + 2] == 'x' && board[x + 3][y + 3] == 'x' && board[x + 4][y + 4] == 'x') {

					return 'X';
				}
				else if (board[x][y] == 'x' && board[x][y + 1] == 'x' && board[x][y + 2] == 'x' && board[x][y + 3] == 'x' && board[x][y + 4] == 'x') {

					return 'X';
				}
				
			}
		}
	}
	return 'N';
}
bool isFull(vector<vector<char>>board) {
	vector<char> row = board[0];
	for (int x = 0; x < row.size(); x++) {
		for (int y = 0; y < (board.size()); y++) {
			if (board[x][y] == '.') {
				return false;
			}
		}
	}
	return true;
}


int main() {
	int m=0;
	int n=0;
	int x;
	int y;
	string col;
	int Player = 0;

	while (!((m > 4) && (n > 4) && (m < 26) && (n < 50))) {
		cout << "Max value rows: 50, max value columns: 26\n";
		cout << "Min value rows and columns: 5  \n";
		cout << "Enter numer of columns: >>";
		cin >> n;
		cout << "Enter numer of rows: >>";
		cin >> m;
	}
	
	vector<vector<char>>board=createBoard(m, n);
	printBoard(board,m,n);
	cout << "If you wont exit the programm, enter 'quit',  \n";

	while (true) {
		do {
			cout << "Enter the column:\n";
			cin >> col;
			if (col == "quit") {
				exit(0);
			}
			x = toupper(col[0]) - 'A';//obcina pierwsza litere
			cout << "Enter the row:\n";
			cin >> y;
			
		} while (!isValid(board, x, y));
		if (Player == 1)
		{
			board[y][x] = 'x';
			Player = 2;
		}
		else {
			board[y][x] = 'o';
			Player = 1;
		}

		printBoard(board, m, n);
		if (checkTheWinner(board) == 'O'|| checkTheWinner(board) == 'X')
			cout << checkTheWinner(board) << " WON !";
		else if (isFull(board))
			cout << "It's a tie!";
		else
		{
			continue;
		}
	}

	
		
}