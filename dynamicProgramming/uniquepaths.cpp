//subsequence of all path...
//318662624
#include<bits/stdc++.h>



int recursion(int i,int col){
        if(i<0 || col<0 )return 0;
        if(i==0 && col==0)return 1;
        int nottake=recursion(i-1,col);   
        int take=recursion(i,col-1);
       
        return take + nottake;
}

int memo(int i,int col,vector<vector<int>>& dp){
        if(i<0 || col<0 )return 0;
        if(i==0 && col==0)return 1;
        if(dp[i][col]!=-1)return dp[i][col];
        int nottake=recursion(i-1,col,dp);   
        int take=recursion(i,col-1,dp);
       
        return dp[i][col]=take + nottake;
}


int spaceopti(int row,int col){
       vector<int>dp(col,0);
        for(int i=0;i<row;i++){
            vector<int>temp(col,0);
            for(int j=0;j<col;j++){
                if(i==0 && j==0)temp[0]=1;
                else{
                    int nottake=0;
                    if(i>0){
                        nottake=dp[j];
                    }
                    int take=0;
                    if(j>0){
                        take=temp[j-1];
                    }  
                    temp[j]=take + nottake;
                }  
            }
            dp=temp;
        }
        return dp[col-1];
    }


int tabulation(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0)
                    dp[i][j] = 1;
                else {
                    int up = 0, left = 0;
                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) left = dp[i][j-1];
                    dp[i][j] = up + left;
                }
            }
        }
        
        return dp[m-1][n-1];
    }

int main(){

	int n=3 //number of rows
	int m=7 //no of colums
	int num1=recursion(n-1,m-1);
	cout<<num1<<endl;

	int num2=memo(n-1,m-1,dp);
	vector<vector<int>>dp(n,vector<int>(m,-1));
	cout<<num2<<endl;

}