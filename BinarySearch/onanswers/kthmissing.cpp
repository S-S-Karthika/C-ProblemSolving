//Example 1:     find the kth missing number.
//Input Format: vec[]={4,7,9,10}, k = 1
//Result: 1
//Explanation: The missing numbers are 1, 2, 3, 5, 6, 8, 11, 12, ……, and so on. Since 'k' is 1, the first missing element is 1.


#include<iostream>
#include<vector>
using namespace std;


int brute(vector<int>arr,int k){

int n = arr.size();

for(int i=0;i<n;i++){
if(arr[i]>k){
return k;
}
k++;
}
return k;
}


int optimal(vector<int>arr,int k){

int low=0,high=arr.size()-1;

while(low<=high){
int mid =low+(high-low)/2;
if((arr[mid]-(mid+1))  < k){
low=mid+1;
}else{
high =mid-1;
}
}
return low+k;
}




int main(){

vector<int>arr={4,7,9,10};
int k=4;

int ans = brute(arr,k);
int answer=optimal(arr,k);
cout<<ans;
cout<<answer;
return 0;

}