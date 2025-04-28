//Example 1:
// Input Format: N = 5, arr[] = {1,2,3,4,5}, limit = 8
//Result: 3
//Explanation: We can get a sum of 15(1 + 2 + 3 + 4 + 5) if we choose 1 as a divisor. 
//The sum is 9(1 + 1 + 2 + 2 + 3)  if we choose 2 as a divisor. Upon dividing all the elements of the array by 3, we get 1,1,1,2,2 //respectively. Now, their sum is equal to 7 <= 8 i.e. the threshold value. So, 3 is the minimum possible answer.



#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int smallthreshold(int mid, vector<int>arr){
int n=arr.size() , sum=0;
for(int i=0;i<n;i++){
	sum+=ceil((double)arr[i]/mid);
}
return sum;
}


int threshold(vector<int>arr,int limit){

int low= *min_element(arr.begin(),arr.end());
int high = *max_element(arr.begin(),arr.end());
int ans=-1;
while(low<=high){

int mid =low+(high-low)/2;
if(smallthreshold(mid,arr)<=limit){
ans=mid;
high=mid-1;
}else{
low=mid+1;
}

}
return ans;
}


int main(){

vector<int>arr={1,2,3,4,5};
int limit =8;
int small = threshold(arr,limit);
cout<<small;
return 0;
}