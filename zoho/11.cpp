// Prime factor – sort the array based on the minimum factor they have

#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int>a,pair<int,int>b){
if(a.second==b.second)return a.first>b.first;
return a.second<b.second;
}

int primefactors(int num){
	
	int count=0;
	for(int i=2;i*i<=num;i++){
		while(num%i==0){
			count++;
			num/=i;
		}
	}
	if(num>1)count++;
return count;
}

int main(){
vector<int>arr={12,34,14,89};
int n=arr.size();
vector<pair<int,int>>factorcount;

for(int num:arr){
	int count=primefactors(num);
	factorcount.push_back({num,count});
}

sort(factorcount.begin(),factorcount.end(),compare);
for(auto& pair:factorcount){
	cout<<pair.first<<" : "<<pair.second<<endl;
}

return 0;
}