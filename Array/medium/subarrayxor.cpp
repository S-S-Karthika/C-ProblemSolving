//Example 1:
//Input Format: A = [4, 2, 2, 6, 4] , k = 6
//Result: 4
//Explanation: The subarrays having XOR of their elements as 6 are  [4, 2], [4, 2, 2, 6, 4], [2, 2, //6], [6]



#include<iostream>
#include<vector>
#include<map>
using namespace std;


int subarraysum(vector<int>arr,int k){
int sum=0,n=arr.size(),count=0;
map<int,int>mpp;
mpp[sum]++;
   for(int i=0;i<n;i++){
	sum=sum^arr[i];
	int x=sum^k;
	count+=mpp[x];
	mpp[sum]++;
   }
return count;
}



int main(){

vector<int>arr={4, 2, 2, 6, 4};
int target =6;
int total = subarraysum(arr,target);
cout<<total;
return 0;

}