//Input: nums = [7,2,5,10,8], k = 2
//Output: 18
//Explanation: There are four ways to split nums into two subarrays.
//The best way is to split it into [7,2,5] and [10,8], where the largest //sum among the two subarrays is only 18.


#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int split(vector<int>arr,int mid){
	int sum=1,currsum=0,n=arr.size();
	for(int i=0;i<n;i++){
		if(currsum+arr[i]>mid){
		sum++; currsum=arr[i];
		}else{
		currsum+=arr[i];
		}
	}
return sum;
}


int splitarray(vector<int>arr,int k){
	
	int low=*max_element(arr.begin(),arr.end());
	int high=accumulate(arr.begin(),arr.end(),0);
	while(low<=high){
		int mid=low+(high-low)/2;
		if(split(arr,mid)>k){
			
			low=mid+1;
		}else{
			high=mid-1;
		}
	}
	return low;
}

int main(){

	vector<int>arr={7,2,5,10,8};
	int k=2;
	int ans =splitarray(arr,k);
	cout<<ans;
	return 0;

}