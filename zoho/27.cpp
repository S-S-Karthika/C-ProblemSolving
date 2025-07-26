//Given an array of integers of size n. Convert the array in such a way that if next valid
//number is same as current number, double its value and replace the next number with 0.

#include <bits/stdc++.h>
using namespace std;



int main(){

vector<int>arr={2,2,0,0,4,0,8};
int j=0;
for(int i=1;i<arr.size();i++){
  if(arr[i]==arr[i-1]){
	arr[i-1]=2*arr[i];
	arr[i]=0;
  }
}
for(int num :arr){
  if(num!=0){
	arr[j++]=num;
  }
}
while(j<arr.size()){
	arr[j++]=0;
}

for(int num :arr)cout<<num<<" ";
}


