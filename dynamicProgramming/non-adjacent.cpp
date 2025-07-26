#include<bits/stdc++.h>
using namespace std;

int recursion(vector<int>num,int n){
	if(n<0)return 0;
	if(n==0)return num[0];
	
	int left=num[n]+recursion(num,n-2);
	int right=recursion(num,n-1);
	return max(left,right);

}

int memorization(vector<int>num,int n,vector<int>& dp){
	if(n<0)return 0;
	if(n==0)return num[0];
	if(dp[n]!=-1)return dp[n];
	
	int left=num[n]+memorization(num,n-2,dp);
	int right=memorization(num,n-1,dp);
	return dp[n]= max(left,right);


}

int tabulation(vector<int>num,int n){
        vector<int>dp(n+1,0);
        dp[0]=num[0];
        for(int i=1;i<=n;i++){
            int left=num[i];
             if(i>1){
                left=num[i]+dp[i-2];
             }
             int right=dp[i-1];
            dp[i]= max(left,right);
        }

        return dp[n];


}


int spaceopti(vector<int>num,int n){

	int prev=num[0],prev1=0;
        for(int i=1;i<=n;i++){
            int left=num[i];
             if(i>1){
                left=num[i]+prev1;
             }
             int right=prev;
            int curr= max(left,right);
            prev1=prev;
            prev=curr;
        }

        return prev;


}




int main(){

vector<int>arr={1,3,4,5,6};
int n=arr.size()-1;

int num1=recursion(arr,n);
cout<<num1<<endl;

vector<int>dp(n+1,-1);
int num2=memorization(arr,n,dp);
cout<<num2<<endl;

int num3=tabulation(arr,n);
cout<<num3<<endl;

int num4=spaceopti(arr,n);
cout<<num4<<endl;

return 0;
}