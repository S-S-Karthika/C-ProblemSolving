#include<bits/stdc++.h>
using namespace std;

bool recursion(vector<int>& arr,int target,int i){

if(target==0)return true;
if(i==arr.size())return false;

if(recursion(arr,target,i+1))return true;
if(recursion(arr,target-arr[i],i+1))return true;
return false;
}


bool memorization(vector<int>& arr,int target,vector<vector<int>>& dp,int i){
	if(target==0)return true;
	if(i==arr.size())return false;
	if(dp[i][target]!= -1 )return dp[i][target];
	if(memorization(arr,target,dp,i+1))return dp[i][target]=true;
	if(target>=arr[i]){
		if(memorization(arr,target-arr[i],dp,i+1))return dp[i][target]=true;
	}
	return dp[i][target]=false;
}


bool tabulation(vector<int>& arr,int target){
	int n=arr.size();
	vector<vector<bool>>dp(n+1,vector<bool>(target+1,false));

	for(int i=0;i<n;i++)dp[i][0]=true;
	if(arr[0]<=target)dp[0][arr[0]]=true;
	for(int i=1;i<n;i++){
		for(int j=1;j<=target;j++){
			bool nottake=dp[i-1][j];
			bool take=false;
			if(j>=arr[i])take=dp[i-1][j-arr[i]];
			dp[i][j] = take || nottake;
		}
	}
return dp[n-1][target];
}


int spaceopti(vector<int>& arr,int target){

	vector<bool>prev(target+1,false);
	vector<bool>curr(target+1,false);
	int n=arr.size();
	prev[0]=true,curr[0]=true;
	for(int i=1;i<n;i++){
		for(int j=1;j<=target;j++){
			bool nottake=prev[j];
			bool take=false;
			if(j>=arr[i])take=prev[j-arr[i]];
			curr[j] = take || nottake;
		}
		prev=curr;
	}
return prev[target];

	

}

int main(){

	vector<int>arr={1,2,3,4};
	int n=arr.size();
	int sum=6;
	if(recursion(arr,sum,0)){cout<<"It is true"<<endl;}
	else {cout<<"It is False "<<endl;}

	vector<vector<int>>dp(n,vector<int>(sum+1,-1));
	if(memorization(arr,sum,dp,0)){cout<<"It is true"<<endl;}
	else {cout<<"It is False "<<endl;}
	
	if(tabulation(arr,sum)){cout<<"It is true"<<endl;}
	else {cout<<"It is False "<<endl;}

	if(spaceopti(arr,sum)){cout<<"It is true"<<endl;}
	else {cout<<"It is False "<<endl;}
}