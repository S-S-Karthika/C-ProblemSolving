#include<bits/stdc++.h>
using namespace std;

//frog jump with k steps
// Given an array of energy levels, where energy[i] represents the energy level at step i,
// and an integer k representing the maximum number of steps that can be jumped,
// find the minimum energy required to reach the last step (n-1) from the first step (0).
// The energy cost to jump from step i to step j is given by abs(energy[i] - energy[j]).
// The problem can be solved using dynamic programming techniques such as recursion, memorization, tabulation, and space optimization.

int spaceopti(vector<int> energy,int n,int k){

	//no need space optimization because when k==n worst case same as tabulation
	return -1;
}


int tabulation(vector<int> energy,int n,int k){

	vector<int>dp(n+1,0);
	dp[0]=0;
	
	for(int i=1;i<=n;i++){
		int mincost=INT_MAX;
		for(int j=1;j<=k;j++){
			if(i-j>=0){
				int cost=dp[i-j]+abs(energy[i]-energy[i-j]);
				mincost=min(cost,mincost);
			}
		
		}
		dp[i]=mincost;
	}
	return dp[n];

}

int memorization(vector<int> energy,int n,int k,vector<int>& dp){
	if(n==0)return 0;
	int mincost=INT_MAX;
	if(dp[n]!=-1)return dp[n];
	for(int i=1;i<=k;i++){
		if(n-i >=0){
			int cost=memorization(energy,n-i,k,dp)+abs(energy[n]-energy[n-i]);
			mincost=min(mincost,cost);
		}
	}
	return dp[n]=mincost;

}


int recursion(vector<int> energy,int n,int k){
	if(n==0)return 0;
	int mincost=INT_MAX;
	for(int i=1;i<=k;i++){
		if(n-i >=0){
			int cost=recursion(energy,n-i,k)+abs(energy[n]-energy[n-i]);
			mincost=min(mincost,cost);
		}
	}
	return mincost;

}



int main(){

vector<int>energy={20,30,50,10};
int n=energy.size()-1;
int k=2;
int num1=recursion(energy,n,k);
cout<<num1<<endl;

vector<int>dp(n+1,-1);
int num2=memorization(energy,n,k,dp);
cout<<num2<<endl;


int num3=tabulation(energy,n,k);
cout<<num3<<endl;
}