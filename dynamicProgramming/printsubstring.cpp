#include<iostream>
#include<vector>
using namespace std;


int memo(string s1,string s2,int n1,int n2,vector<vector<int>>& dp){
	if(n1 ==0 || n2==0)return 0;
	if(dp[n1][n2]!=-1)return dp[n1][n2];
	if(s1[n1-1] == s2[n2-1])return dp[n1][n2]=1+memo(s1,s2,n1-1,n2-1,dp);
	return dp[n1][n2]= max(memo(s1,s2,n1-1,n2,dp),memo(s1,s2,n1,n2-1,dp));
}

int main(){

string s1="hello",s2="holulye";
int n1=s1.size(),n2=s2.size();
vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));

memo(s1,s2,n1,n2,dp);
string ans="";
while(n1>0 && n2>0){
	if(s1[n1-1] == s2[n2-1]){
		ans=s1[n1-1]+ans;
		n1--;
		n2--;
	}else if(dp[n1-1][n2] > dp[n1][n2-1]){
		n1--;
	}
	else{
		 n2--;
	}
}
cout<<ans;
}