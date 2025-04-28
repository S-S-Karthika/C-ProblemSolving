//Example 1:
//Input Format: arr[] = {1,2,3,4,5,6,7,8,5,1}
//Result: 7
//Explanation: In this example, there is only 1 peak that is at index 7.



#include<iostream>
#include<vector>
using namespace std;


int peakelement(vector<int>&arr){

int low=0,high=arr.size()-1;
while(low<high){
int mid = low+(high-low)/2;
if(arr[mid]<arr[mid+1]){
	low=mid+1;
}else{
high=mid;
}
}
return low;

}


int main(){
vector<int>arr={1,2,3,4,5,6,7,8,5,1};
int peak = peakelement(arr);
cout<<peak;
return 0;

}