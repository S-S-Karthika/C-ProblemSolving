#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;


int spaceoptimization(vector<int>& dist,int n){
	int prev=0,prev1=0,curr=0;
	for(int i=1;i<n;i++){
		int firststep=prev+abs(dist[i]-dist[i-1]);
		int secondstep=INT_MAX;
		if(i>1){
			secondstep=prev1+abs(dist[i]-dist[i-2]);
		}
		curr=min(firststep,secondstep);
		prev1=prev;
		prev=curr;
	}
	return prev;
}


int tabulation(vector<int>& dist,int n){

	vector<int>dp(n,0);
	dp[0]=0;
	for(int i=1;i<n;i++){
		int firststep=dp[i-1]+abs(dist[i]-dist[i-1]);
		int secondstep=INT_MAX;
		if(i>1){
			secondstep=dp[i-2]+abs(dist[i]-dist[i-2]);
		}
		dp[i]=min(firststep,secondstep);
	}
	return dp[n];
}


int memorization(vector<int>& dist,int n,vector<int>& dp){

	if(n==0)return 0;
	if(dp[n]!=-1)return dp[n];
	int left=memorization(dist,n-1,dp)+ abs(dist[n]-dist[n-1]);
	int right=INT_MAX;
	if(n>1){
		right=memorization(dist,n-2,dp)+ abs(dist[n]-dist[n-2]);
	}
	return dp[n]=min(left,right);


}



int recursion(vector<int>& dist,int n){

	if(n==0)return 0;
	int left=recursion(dist,n-1)+ abs(dist[n]-dist[n-1]);
	int right=INT_MAX;
	if(n>1){
		right=recursion(dist,n-2)+ abs(dist[n]-dist[n-2]);
	}
	return min(left,right);
}



int main(){

	vector<int>dist={10,20,30,10,40};
	int num1 = recursion(dist,dist.size()-1);
	cout<<num1<<endl;

	vector<int>dp(dist.size()+1,-1);
	int num2=memorization(dist,dist.size()-1,dp);
	cout<<num2<<endl;

	int num3= tabulation(dist,dist.size());
	cout<<num3<<endl;
	

	int num4= spaceoptimization(dist,dist.size());
	cout<<num4<<endl;
}