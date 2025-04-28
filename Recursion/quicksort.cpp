#include<iostream>
#include<vector>
using namespace std;

int pivotIndex(vector<int>&arr,int low,int high){
	int i=low+1,j=high;
	int pivot=arr[low];
	while(i<=j){
	     while(arr[i]<=pivot  && i<=high)i++;     //arr[i]>=pivot   for desending
	     while(arr[j]>pivot && j>=low)j--;        //arr[j]<pivot
	     if(i<j)swap(arr[i++],arr[j--]);
	}
	swap(arr[low],arr[j]);
       return j;	
}



void qs(vector<int>&arr, int low, int high){
	if(low>=high)return;
	int partition = pivotIndex(arr,low,high);
	qs(arr,low,partition-1);
	qs(arr,partition+1,high);
}
	


int main(){
	vector<int>arr={7,6,8,3,5,1,0,2};
	qs(arr,0,arr.size()-1);
	for (int num : arr)
       	   cout << num << " ";
           cout << endl;
        return 0;

}