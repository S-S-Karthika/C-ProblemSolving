#include<iostream>
#include<vector>
#include<string>
using namespace std;

void solve(int col,int n,vector<int>& left,vector<int>& upmost,vector<int>& downmost,vector<vector<string>>& result,vector<string>& board){
	if(col == n){
		result.push_back(board);
		return;
	}

	for(int row=0;row<n;row++){
		if(left[row]==0 && upmost[(n-1)+col-row]==0 && downmost[row+col]==0){
			board[row][col]='Q';
			left[row]=1;
			upmost[(n-1)+col-row]=1;
			downmost[row+col]=1;
			solve(col+1,n,left,upmost,downmost,result,board);
			board[row][col]='.';
			left[row]=0;
			upmost[(n-1)+col-row]=0;
			downmost[row+col]=0;
		}
	}
}


vector<vector<string>>NQueens(int n){

	vector<vector<string>>result;
	vector<string>board(n);
	string s(n,'.');
	for (int i=0;i<n;i++){
		board[i]=s;
	}
	vector<int>left(n,0);
	vector<int>upmost(2*n-1,0);
	vector<int>downmost(2*n-1,0);
	solve(0,n,left,upmost,downmost,result,board);
	return result;
}


int main(){
	int n=8;
	vector<vector<string>> result =NQueens(n);
	for(auto& subset : result)
	{
		cout<<"[ \n\n";
		for(string num:subset){
			cout<<"\t[ ";
			cout<<num<<" ";
			cout<<" ]\n";
		}
		cout<<" ]\n\n";
	}
	return 0;       
}