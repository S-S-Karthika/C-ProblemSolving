//Example 1:
//Input Format: N = 8, arr[] = {7, 7, 7, 7, 13, 11, 12, 7}, m = 2, k = 3
//Result: 12
//Explanation: On the 12th the first 4 flowers and the last 3 flowers would have already bloomed. So, we can easily make 2 //bouquets, one with the first 3 and another with the last 3 flowers.
// m= no of boquets , n = number of adjacet flowers , return in which day we got m bouquets with k flowers






#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int bouquets(vector<int>arr,int mid,int k){
	int count=0,flowers=0;
	int n=arr.size();
	for(int i=0;i<n;i++){
		if(arr[i]<=mid){
			flowers++;
			if(flowers==k){
				count++;
				flowers=0;
			}
		}else{
			flowers=0;
		}

	}
return count;

}


int noOfbouqets(vector<int>arr,int m, int n){

int low =*min_element(arr.begin(), arr.end());
int high =*max_element(arr.begin(), arr.end());

int ans =-1;
while(low<=high){
	
	int mid= low+(high-low)/2;
	if(bouquets(arr,mid,n)>=m){
		ans=mid;
		high=mid-1;
	}else{
		low=mid+1;
	}

}
return ans;
}


int main(){

vector<int>arr={7, 7, 7, 7, 13, 11, 12, 7};
int  m = 2, k = 3;

int count = noOfbouqets(arr,m,k);
cout<<count;
return 0;


}