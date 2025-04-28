//Example 1:
//Input Format: N = 4, boards[] = {5, 5, 5, 5}, k = 2
//Result: 10
//Explanation: We can divide the boards into 2 equal-sized partitions, so each painter gets 10 units of the board //and the total time taken is 10.


#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int allocation(vector<int>arr,int mid){

	int cnt=1,currsum=0,n=arr.size();
	for(int i=0;i<n;i++){
		if(currsum+arr[i]>mid){
			cnt++;
			currsum=arr[i];
		}else{
			currsum+=arr[i];
		}
	}
return cnt;

}


int painter(vector<int>arr,int k){
	int low=*max_element(arr.begin(),arr.end());
	int high=accumulate(arr.begin(),arr.end(),0);
	while(low<=high){
		int mid =low+(high-low)/2;
		if(allocation(arr,mid)>k){
			low=mid+1;
		}else{
			high=mid-1;
		}
	}
return low;
}


int main(){

	vector<int>arr={5, 5, 5, 5};
	int k=2;
	int allocate=painter(arr,k);
	cout<<allocate;
	return 0;
}

