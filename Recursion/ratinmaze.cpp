#include<iostream>
#include<vector>
using namespace std;

void solve(int x,int y,vector<vector<int>>maze,int n,vector<vector<int>>& visited,string curr,vector<string>& result){
    if(x==n-1 &&  y==n-1){
        result.push_back(curr);
        return;
    }
    visited[x][y]=1;
    vector<int>dx={1,0,0,-1};
    vector<int>dy={0,-1,1,0};
    vector<char>direction={'d','l','r','u'};


    for(int i=0;i<4;i++){
        int newx=x+dx[i];
        int newy=y+dy[i];
        if(newx>=0 && newy>=0 && newx<n && newy<n && visited[newx][newy]==0 && maze[newx][newy]==1){
            solve(newx,newy,maze,visited,curr+direction[i],result);
        }
    }
    visited[x][y]=0;
}

vector<string> paths(vector<vector<int>>maze,int n){
    if(maze[0][0]==0 || maze[n-1][n-1]==0)return {};
    vector<vector<int>>visited(vector<int>(n,0));
    vector<string>result;
    solve(0,0,maze,n,visited,"",result);
    return result;
}


int main(){
    vector<vector<int>>maze={{1,0,0,0},{1,1,0,1},{0,1,0,0},{1,1,1,1}};
    int n=maze.size();
    vector<string>paths=reach(maze,n);
    if(paths.empty()){
        cout<<"no we can't reach"<<end;
    }else{
        cout<<"The paths are"<<endl;
        for(string str:paths)cout<<str<<" ";
    }
    return 0;
}