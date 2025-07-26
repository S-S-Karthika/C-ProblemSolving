#include <bits/stdc++.h>
using namespace std;


int memo(vector<vector<int>>& grid,int row,int col,vector<vector<int>>& dp){
        if(row<0 || col<0)return 0;
        if(row==0 && col==0)
            return grid[0][0];
        if(dp[row][col]!=-1)return dp[row][col];
            int right=INT_MAX,left=INT_MAX;
            if(col>0)right=grid[row][col]+recursion(grid,row,col-1,dp);
            if(row>0)left=grid[row][col]+recursion(grid,row-1,col,dp);
            return dp[row][col]=min(right,left);
    
}



int tabulation(vector<vector<int>>& grid){

	vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),0));
        int row=grid.size(),col=grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i==0 && j==0)dp[i][j]=grid[0][0];
                else{
                    int left=INT_MAX,top=INT_MAX;
                    if(j>0)left=grid[i][j]+dp[i][j-1];
                    if(i>0)top=grid[i][j] + dp[i-1][j];
                    dp[i][j]=min(left,top);
                }
            }
        }
        return dp[row-1][col-1];
}




int main() {
    vector<vector<int>> matrix{
        {5, 9, 6},
        {11, 5, 2}
    };

    int n = matrix.size();
    int m = matrix[0].size();
     vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
    cout << "Minimum sum path: " << memo( matrix,n,m,dp) << endl;
    return 0;
}