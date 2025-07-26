//Missing Number

#include <bits/stdc++.h>
using namespace std;


void sort(vector<vector<int>>& matrix,int row,int col,int rowlen){
	vector<int>arr;
	int n=rowlen,m=matrix[0].size();
	int i=row,j=col,k=0;
	while(i<n&& j<m){
		arr.push_back(matrix[i++][j++]);
	}
	sort(arr.begin(),arr.end());
	i=row,j=col;
	while(i<n && j<m){
		matrix[i++][j++]=arr[k++];
	}
}


int main(){

vector<vector<int>>matrix={{3,3,1,1},{2,2,1,2},{1,1,1,2}};

vector<int>diagonal;
int n=matrix.size();
int m=matrix[0].size();

for(int col=0;col<n;col++){
	sort(matrix,0,col,n);
}
for(int row=1;row<m;row++){
	sort(matrix,row,0,n);
}

for(auto & subset:matrix){
for(int num:subset)cout<<num<<" ";
cout<<endl;
}
}


