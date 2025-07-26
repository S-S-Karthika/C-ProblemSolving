//with obstacles

#include<bits/stdc++.h>
using namespace std;


 int recursion(vector<vector<int>>& grid,int i,int col){
        if(i<0 || col<0 ||grid[i][col])return 0;
        if(i==0 && col==0)return 1;
        int nottake = recursion(grid,i-1,col);   
        int take=recursion(grid,i,col-1);
        return take + nottake;
        
    }


int memo(vector<vector<int>>& grid,int i,int col,vector<vector<int>>& dp){
        
        if(i<0 || col<0 ||grid[i][col]==1)return 0;
        if(i==0 && col==0)return 1;
        if(dp[i][col]!=-1)return dp[i][col];
        int nottake = memo(grid,i-1,col,dp);   
        int take=memo(grid,i,col-1,dp);
        return dp[i][col]=take + nottake;

}


int tabulation(vector<vector<int>>& obstacleGrid,int row,int col){
        vector<vector<int>>dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                }else if(i==0 && j==0){
                    dp[i][j]=1;
                }else{
                    int nottake=0,take=0;
                    if(i>0)nottake =dp[i-1][j];
                    if(j>0)take=dp[i][j-1];
                    dp[i][j]=take + nottake;
                }      
            }
        }
           
        
        return dp[row-1][col-1];

    }


    int space(vector<vector<int>>& obstacleGrid,int row,int col){
        vector<int>dp(col,0);

        for(int i=0;i<col;i++){
            if (obstacleGrid[0][i] == 1) break;
            dp[i]=1;
        }
       
        for(int i=1;i<row;i++){
            vector<int>temp(col,0);
            if (obstacleGrid[i][0] == 0) {
                temp[0] = dp[0];
            }
            for(int j=1;j<col;j++){
                if(obstacleGrid[i][j]!=1){
                     int nottake =dp[j];
                     int take=temp[j-1];
                     temp[j]=take + nottake;
                }     
            }
            dp=temp;
        }
        return dp[col-1];

    }


int main(){

vector<vector<int>>obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}}
if (obstacleGrid[0][0] == 1) return 0;


int num1=recursion(obstacleGrid,obstacleGrid.size()-1,obstacleGrid[0].size()-1);
cout<<num1<<endl;


vector<vector<int>>dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));
int num2=memo(obstacleGrid,obstacleGrid.size()-1,obstacleGrid[0].size()-1,dp);
cout<<num2<<endl;


return 0;
}