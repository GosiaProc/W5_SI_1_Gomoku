#include <iostream>
#include <vector>

using namespace std;

void printVector2D (vector<vector<char>> v,int n,int m){

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

vector<vector<char>> createVector2D(int m, int n) {
	
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
	return (y < board.size())
		&& (x< row.size())
		&& (x>=0)
		&& (y>=0)
		&& (board[y][x] == '.');

}


int main() {
	int m=0;
	int n=0;
	int x;
	int y;
	char col;
	int Player = 0;

	while (!((m > 4) && (n > 4) && (m < 26) && (n < 50))) {
		cout << "Max value rows: 50, max value columns: 26\n";
		cout << "Min value rows and columns: 5  \n";
		cout << "Enter numer of columns: >>";
		cin >> n;
		cout << "Enter numer of rows: >>";
		cin >> m;
	}
	
	vector<vector<char>>board=createVector2D(m, n);
	printVector2D(board,m,n);
	while (true) {
		do {
			cout << "Enter the column:\n";
			cin >> col;
			x = toupper(col) - 'A';
			cout << "Enter the row:\n";
			cin >> y;
			cout << x << endl << y << endl;
		} while (!isValid(board, x, y));

		if (Player == 1)
		{
			board[y][x] = 'x';
			Player = 0;
		}
		else {
			board[y][x] = 'o';
			Player = 1;
		}

		printVector2D(board, m, n);
	}

	
		
}