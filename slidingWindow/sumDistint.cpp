#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int findMax(vector<int>nums,int k){
	int n = nums.size();
        if (k > n) return 0; 
	unordered_set<int>set;
        int sum = 0,maxi=0,left=0,right=0;
	while(right<n){
		while(set.count(nums[right] ) ){
			sum-=nums[left];
			set.erase(nums[left]);
			left++;
		}
		sum+=nums[right];
		set.insert(nums[right]);
		if(k==right-left+1){
			maxi=max(maxi,sum);
			sum-=nums[left];
			set.erase(nums[left]);
			left++;
		}
		right++;
	}
return maxi;
	        
}

int find2Max(vector<int>nums,int k){
	int n = nums.size()  , maxi=-1;
        if (k > n) return 0; 
	unordered_set<int>set;

	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=i;j<n;j++){
			if(set.count(nums[j]))break;
			set.insert(nums[j]);
			sum+=nums[j];
			if(j-i+1 ==k){
				maxi=max(sum,maxi);
				break;
			}
		}

	}
	return maxi;

}


int main(){
	vector<int>nums={1,5,4,2,9,9,9};
	int k=3;
	int ans = find2Max(nums,k);
	cout<<"The Maximum of the subarray is : "<<ans;
	return 0;
}