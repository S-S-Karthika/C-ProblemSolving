//Sort the given elements in decending order based on the number of factors of each
//element

#include <bits/stdc++.h>
using namespace std;

int factors(int num){
if(num<=1)return 0;
int count=0;
while(num%2 ==0){
	count++;
	num/=2;
}
for(int i=3;i<=num;i++){
	while(num%i ==0){
		count++;
		num/=i;
	}
}
return count;
}

bool compare(pair<int,int> a,pair<int,int> b){
	if(a.second!=b.second)return a.second>b.second;
	a.first>b.first;
}

int main(){

vector<int>arr={20,6,3,7};
vector<pair<int,int>>mpp;
for(int num:arr){
int count=factors(num);
mpp.push_back({num,count});
}
sort(mpp.begin(),mpp.end(),compare);
for(auto & it:mpp){
cout<<it.second<<" : "<<it.first<<endl;
}
}


