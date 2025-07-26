// Sort the array elements in descending order according to their frequency of occurrence

#include<bits/stdc++.h>
using namespace std;


bool compare(pair<int,int>a,pair<int,int>b){
if(a.second==b.second)return a.first>b.first;
return a.second>b.second;
}


int main(){

vector<int>arr={0,1,2,2,2,4,4,9,5,5,9};
unordered_map<int,int>mpp;
for(int num : arr)mpp[num]++;
vector<pair<int,int>>occurance;
for(auto& it:mpp){
	occurance.push_back(it);
}
sort(occurance.begin(),occurance.end(),compare);
for(auto& pair:occurance){
	cout<<pair.first<<" : "<<pair.second<<endl;
}
}

