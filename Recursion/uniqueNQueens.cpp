
//getting all possible with rules

#include<iostream>
#include<vector>
using namespace std;
#define N 4  //#define N 8 

void printBoard(vector<vector<int>>& board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(vector<vector<int>>& board,int row,int col){
	int duprow=row;
	int dupcol =col;
	while(col>=0){
		if(board[row][col])return false;
		col--;
	}
	col= dupcol;
	row=duprow;
	while(col>=0 && row<N){
		if(board[row][col])return false;
		col--;
		row++;
	}
	col=dupcol;
	row=duprow;
	while(row>=0 && col>=0){
		if(board[row][col])return false;
		col--;row--;
	}
	return true;
}

void solve(int col,vector<vector<int>>& board,vector<vector<vector<int>>>& solutions  ){

	if(col==N){
		solutions.push_back(board);
		return;
	}

	for(int row=0;row<N;row++){
             if(isSafe(board,row,col)){	
		board[row][col]=1;
		solve(col+1,board,solutions);
		board[row][col]=0;

	}
	}



}



int main() {
    vector<vector<int>> board(N, vector<int>(N, 0));
    vector<vector<vector<int>>> solutions;

    solve(0, board, solutions);

    cout << "Total solutions: " << solutions.size() << "\n\n";
    for (auto& sol : solutions) {
        printBoard(sol);
    }

    return 0;
}