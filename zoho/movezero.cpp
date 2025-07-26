#include<bits/stdc++.h>
using namespace std;
//move all zeroes to the end of the array and double the value of adjacent elements if they are equal

int main(){

vector<int>arr={0,2,2,2,0,6,6,0,0,8};

int n=arr.size();
for(int i=1;i<n;i++){
if(arr[i]==arr[i-1] && arr[i]!=0){
arr[i-1]=2*arr[i];
arr[i]=0;
}
}

int j=0;
for(int i=0;i<n;i++){
if(arr[i]!=0)arr[j++]=arr[i];
}

while(j<n)arr[j++]=0;

for(int i=0;i<n;i++)cout<<arr[i]<<" ";
}