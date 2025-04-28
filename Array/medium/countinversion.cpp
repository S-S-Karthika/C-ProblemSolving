#include<iostream>
#include<vector>
using namespace std;


int merge(vector<int>&arr,int low,int mid ,int high){

vector<int>temp;
int left=low,right=mid+1,count=0;

while(left<=mid && right<=high){

if(arr[left]<=arr[right]){
	temp.push_back(arr[left]);
	left++;
}else{
	temp.push_back(arr[right]);
	count+=(mid - left + 1);
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


    for (int i = 0; i < temp.size(); i++) {
        arr[low + i] = temp[i];
    }

return count;

}


int mergesort(vector<int>&arr,int low ,int high){

	
	if(low>=high)return 0;
		
		int mid=low+(high-low)/2;
		int num=0;
		num+=mergesort(arr,low,mid);
		num+=mergesort(arr,mid+1,high);
		num+=merge(arr,low,mid,high);
return num;	

}


int main(){

vector<int>arr={10,9,4,7,8,5,1};
int low=0,high=arr.size();
int num=mergesort(arr,low,high-1);
cout<<num<<" ";

return 0;
}