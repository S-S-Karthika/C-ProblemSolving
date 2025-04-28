//Example 1:
//Input Format: N = 4, a[] = {7, 15, 6, 3}, h = 8
//Result: 5
//Explanation: If Koko eats 5 bananas/hr, he will take 2, 3, 2, and 1 hour to eat the piles accordingly. So, he will take 8 hours // to complete all the piles. 



#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int calculatehrs(vector<int>arr,int mid){
	int ans=0;
	for(int i=0;i<arr.size();i++){
		ans += ceil((double)arr[i] / mid);
	}
	
return ans;

}

int max(vector<int>arr){
int maxi=0;
for(int i=0;i<arr.size();i++){
 if(arr[i]>maxi)maxi=arr[i];
}
return maxi;
}

int optimal(vector<int>arr,int h){
	int low=1,ans=-1;
	int high = max(arr);
	while(low<=high){
		int mid = (low+high)/2;
		int hrs = calculatehrs(arr,mid);
		if(hrs <= h){
			ans=mid;
			high=mid-1;
		}else{
			low=mid+1;
		}
	}
	return ans;

}

int brute(vector<int>arr,int h){
int high = max(arr);
for(int i=1;i<high;i++){
int hrs = calculatehrs(arr,i);
if(hrs<=h)return i;
}

}




int main(){
	vector<int> arr={7, 15, 6, 3};
	int h=8;
	int hours=brute(arr,h);
	int hrs = optimal(arr,h);
	cout<<hours;
	cout<<hrs;
	return 0;

}

