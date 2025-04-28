// Example 1:
// Input Format: N = 6, k = 4, arr[] = {0,3,4,7,10,9}
// Result: 3
// Explanation: The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions {0, 3, 7, 10}. Here the distances between cows are 3, 4, and 3 respectively. We cannot make the minimum distance greater than 3 in any 
// ways.    k= number of cows to be placed.


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool canPlace(vector<int>&arr, int dist , int k,int n){
	int cntcows=1,last=arr[0];
	for(int i=1;i<n;i++){
		if(arr[i]-last>=dist){
			cntcows++;
			last=arr[i];
		}
		if(cntcows>=k)return true;
	}
	return false;
}

int aggresivecows(vector<int>&arr , int k){
	sort(arr.begin(), arr.end());
	int n=arr.size();
	int limit = arr[n-1]-arr[0];
	for(int i=1;i<=limit;i++){
		if(canPlace(arr,i,k,n)==false)return (i-1);
	}	
	return limit;
}

int aggresivecows2(vector<int>&arr , int k){
	sort(arr.begin(), arr.end());
	int n=arr.size();
	int low=1,high=arr[n-1]-arr[0];
	while(low<=high){
		int mid =low+(high-low)/2;
		if(canPlace(arr,mid,k,n)==true){
			low=mid+1;
		}else{
			high=mid-1;
		}
	}
	return high;
}


int main(){
	vector<int>arr={0,3,4,7,10,9};
	int k=4;
	int num = aggresivecows(arr,k);
	int numbinary = aggresivecows2(arr,k);
	cout<<num<<endl;
	cout<<numbinary;
	return 0;
}