#include<iostream>
#include<vector>
using namespace std;


void merge(vector<int>&arr,int low,int mid ,int high){

vector<int>temp;
int left=low,right=mid+1;

while(left<=mid && right<=high){

if(arr[left]<arr[right]){
	temp.push_back(arr[left]);
	left++;
}else{
	temp.push_back(arr[right]);
	right++;
}

}
while(left<=mid){
	temp.push_back(arr[left]);
	left++;
}
while(right<=high){
	temp.push_back(arr[right]);
	right++;
}

for(int i=0;i<temp.size();i++){
	arr[low+i]=temp[i];
}

}


void mergesort(vector<int>&arr,int low ,int high){

	
	if(low>=high)return;
	
		int mid=low+(high-low)/2;
		mergesort(arr,low,mid);
		mergesort(arr,mid+1,high);
		merge(arr,low,mid,high);
	

}


int main(){

vector<int>arr={10,9,4,7,8,5,1};
int low=0,high=arr.size();
mergesort(arr,low,high-1);
for(int num : arr){
cout<<num<<" ";
}
return 0;
}