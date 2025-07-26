// Given an array A[] and a number x, check for pair in A[] with sum as x.

#include <bits/stdc++.h>
using namespace std;



int main(){

vector<int>arr={2,2,0,0,4,0,8};
int target=10;
unordered_map<int,int>mpp;
for(int i=0;i<arr.size();i++){
int total=target-arr[i];
if(mpp.find(total)!=mpp.end()){
	cout<<mpp[arr[i]]<<" "<<i;
	return 0;
}
mpp[arr[i]]=i;
}
}


