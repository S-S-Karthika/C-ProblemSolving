#include<iostream>
#include<vector>
using namespace std;


int tabulation(int n){

    vector<int>dp(n+1,0);
    dp[0]=0;
    dp[1]=1;

        for(int i=2;i<n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
    return dp[n-1];
}

int spaceoptimization(int n){

int prev=0,prev1=1;
int curr=0;
for(int i=2;i<=n;i++){
	curr=prev+prev1;
	prev=prev1;
	prev1=curr;
}
return prev1;
}


int memorization(int n,vector<int>dp){

	if(n<=1)return n;
	if(dp[n]!=-1)return dp[n];
	return dp[n] = memorization(n-2,dp)+memorization(n-1,dp);

}



int recursion(int n){

	if(n<=1)return n;
	return recursion(n-1)+recursion(n-2);

}


int main(){

int n=10;
int num1=recursion(n);
cout<<num1<<endl;

vector<int>dp(n+1,-1);
int num2=memorization(n,dp);
cout<<num2<<endl;

int num3=tabulation(n+1);
cout<<num3<<endl;


int num4=spaceoptimization(n);
cout<<num4;


return 0;
}