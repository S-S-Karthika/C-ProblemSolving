//partition sum

#include<bits/stdc++.h>
using namespace std;

bool recursion(vector<int>& nums,int target,int n){
        if(target == 0)return true;
        if(n==0)return false;
        if(recursion(nums,target,n-1))return true;
        if(nums[n]<=target && recursion(nums,target-nums[n],n-1))return true;
        return false;

    }


 bool memorization(vector<int>& nums,int target,int n,vector<vector<int>>dp){
        if(target == 0)return true;
        if(n==0)return false;
        if(dp[n][target]!=-1)return dp[n][target];
        if(recursion(nums,target,n-1,dp))return dp[n][target]=true;
        if(nums[n]<=target && recursion(nums,target-nums[n],n-1,dp))return dp[n][target]=true;
        return dp[n][target]= false;

    }

bool tabulation(vector<int>& nums) {
        int sum=0,n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2 != 0)return false;
        sum=sum/2;
        vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
            for(int i=0;i<n;i++)dp[i][0]=true;
            if(nums[0]<=sum)dp[0][nums[0]]=true;
            for(int i=1;i<n;i++){
                for(int j=1;j<=sum;j++){
                    bool nottake=dp[i-1][j];
                    bool take=false;
                    if(j>=nums[i])take=dp[i-1][j-nums[i]];
                    dp[i][j] = take || nottake;
                }
            }
        return dp[n-1][sum];

    }


bool spaceopti (vector<int>& nums) {
        int sum=0,n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2 != 0)return false;
        sum=sum/2;
        vector<bool>prev(sum+1,false);
        vector<bool>curr(sum+1,false);
            
            if(nums[0]<=sum)prev[nums[0]]=true;
            for(int i=1;i<n;i++){
                curr[0]=true,prev[0]=true;
                for(int j=1;j<=sum;j++){
                    bool nottake=prev[j];
                    bool take=false;
                    if(j>=nums[i])take=prev[j-nums[i]];
                    curr[j] = take || nottake;
                }
                prev=curr;
            }
        return prev[sum];

    }

int main(){

	vector<int>arr={1,2,3,4};
	int n=arr.size();
	int total=0;
	 int sum=0,n=nums.size();


        for(int i=0;i<n;i++){
            total+=nums[i];
        }
	if(total%2 ==0)cout<<"Not able to partition"<<endl;
	else{
		if(recursion(arr,total/2,n-1)){cout<<"It is true"<<endl;}
		else {cout<<"It is False "<<endl;}


	//method----2

		vector<vector<int>>dp(n,vector<int>(sum+1,-1));
		if(memorization(arr,total/2,n-1,dp)){cout<<"It is true"<<endl;}
		else {cout<<"It is False "<<endl;}



        if(tabulation(arr)){cout<<"It is true"<<endl;}
	    else {cout<<"It is False "<<endl;}

	    if(spaceopti(arr)){cout<<"It is true"<<endl;}
	    else {cout<<"It is False "<<endl;}
	}



	
	
}