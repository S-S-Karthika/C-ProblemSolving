#include <iostream>
#include<math.h>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

vector<int>unique(int n)
{
    vector<int>ans(n+1,true);
    ans[0]=false;
    ans[1]=false;
    
    for(int i=2;i<=sqrt(n);++i){
        if(ans[i]){
            for(int j =i*i;j<n;j+=i ){
            ans[j]=false;
        }
    }       
    }
     vector<int>result;
    for(int i =2;i<=n;i++){
        if(ans[i]){
            result.push_back(i);
        }
    }
    return result;
    
}

int main(){
    int n=10;
    vector <int> ans = unique(n);
    for(int i=0;i<ans.size();i++){
       
            cout<<i<<",";
        
        
    }
}