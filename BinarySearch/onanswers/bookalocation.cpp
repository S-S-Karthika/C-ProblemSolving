//Input Format: n = 4, m = 2, arr[] = {12, 34, 67, 90}
//Result: 113
//Explanation: The allocation of books will be 12, 34, 67 | 90. One student will get the first 3 books and the other will get the last one.

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int canallocate(vector<int>arr,int mid,int students){
	int cnt=1,last=arr[0];
	for(int i=1;i<arr.size();i++){
		last+=arr[i];
		if(last>mid){
			cnt++;
			last=arr[i];
		}
		
	}
return cnt;
}



int bookalocation(vector<int>arr,int students){
	int n = arr.size();
        if (students > n) return -1;
	int low=*max_element(arr.begin(),arr.end());
	int high=accumulate(arr.begin(),arr.end(),0);
	int ans=-1;
	while(low<=high){
		int mid =low+(high-low)/2;
		if(canallocate(arr,mid,students)>students){
			low=mid+1;
		}else{
			ans=mid;
			high=mid-1;
		}
		
	}
return ans;
}

int main(){

	vector<int>arr={12, 34, 67, 90};
	int m=2 ;
	int pages = bookalocation(arr,m);
	cout<<pages;
	return 0;

}