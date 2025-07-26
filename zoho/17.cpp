//Find Element Appears Once  single-number-ii
#include <bits/stdc++.h>
using namespace std;

int optimize(vector<int>arr){
int result=0;
for(int i=0;i<32;i++){
int bitsum=0;
for(int num: arr){
	if(num & (1<<i))bitsum++;
}
if(bitsum%3 !=0 )result |= (1<<i);
}
return result;
}

int main(){
vector<int>arr={1,0,1,3,1,0,0};
unordered_map<int,int>mpp;

for(int num:arr)mpp[num]++;
for(auto& it: mpp){
	if(it.second == 1){
		cout<<it.first<<endl;
		break;
	}
	
}

int ans=optimize(arr);
cout<<ans;
}
