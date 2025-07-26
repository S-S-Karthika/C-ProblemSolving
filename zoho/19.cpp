//Missing Number

#include <bits/stdc++.h>
using namespace std;

int main(){

vector<int>arr={1,3,4,5,9,2,6,7};
int n=arr.size()+1;
int sum=0;
int total=n*(n+1)/2;
for(int num: arr){
	sum+=num;
}
cout<<total-sum;
}