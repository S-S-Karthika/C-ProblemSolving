//Input Format: N = 10, weights[] = {1,2,3,4,5,6,7,8,9,10}, d = 1
//Result: 55
//Explanation: We have to ship all the goods in a single day. So, the weight capacity should be the summation of all the weights i.e. //55.


#include<iostream>
#include<vector>
#include <numeric>
#include<cmath>
using namespace std;

int func(vector<int>arr,int mid){
int days=0,sum=0;
int n=arr.size();
for(int i=0;i<n;i++){
sum+=arr[i];
if(sum>=mid){
sum=arr[i];
days++;
}
}

return days;
}


int noOfKg(vector<int>arr,int days){

int low=1;
int high = accumulate(arr.begin(), arr.end(), 0);
if(days==1)return high;
int ans=-1;
while(low<=high){

int mid =low+(high-low)/2;
if(func(arr,mid)<=days){
ans=mid;
high=mid-1;
}else{
low=mid+1;
}

}
return ans;
}



int main(){

vector<int>weights={1,2,3,4,5,6,7,8,9,10};
int days =1;
int totalweight = noOfKg(weights,days);
cout<<totalweight;
return 0;

}