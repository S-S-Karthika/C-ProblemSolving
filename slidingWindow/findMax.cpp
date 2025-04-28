#include<iostream>
#include<vector>
using namespace std;

int findMax(vector<int>&nums,int k){
	int n = nums.size();
        if (k > n) return 0; 

        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i]; 
        }

        int maxi = sum;
        for (int i = k; i < n; i++) {
            sum = sum - nums[i - k] + nums[i]; 
            maxi = max(maxi, sum);
        }

        return maxi;
}


int main(){
	vector<int>nums={100,200,300,400};
	int k=2;
	int ans = findMax(nums,k);
	cout<<"The Maximum of the subarray is : "<<ans;
	return 0;
}