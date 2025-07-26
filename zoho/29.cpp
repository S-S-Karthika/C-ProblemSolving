// Kadane’ Algorithm  maximum subarray sum..

#include <bits/stdc++.h>
using namespace std;



int main(){

vector<int>arr={2,2,-1,-5,4,0,8};
int currmax=0;
int maxi=INT_MIN;
for(int num: arr){
currmax=max(currmax+num,num);
maxi=max(maxi,currmax);
}
cout<<maxi;
}


