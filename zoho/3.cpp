//Sort the array odd numbers in ascending and even numbers in descending.

#include<bits/stdc++.h>
using namespace std;


int main(){
vector<int>arr={1,5,2,3,4,4,9};
int n=arr.size();
vector<int>odd;
vector<int>even;

for(int num: arr){
if(num%2==0)even.push_back(num);
else odd.push_back(num);
}
sort(odd.begin(),odd.end());
sort(even.rbegin(),even.rend());

for(int i=0;i<odd.size();i++){
	arr[i]=odd[i];
}
int j=even.size()+1;
for(int num:even){
arr[j++]=num;
}

for(int i=0;i<n;i++)cout<<arr[i]<<" ";
}