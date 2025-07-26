#include <iostream>
#include<vector>
using namespace std;

int main(){

vector<int>num={131,59,67};
vector<int>ans(26,0);
int n=num.size();

for(int i=0;i<n;i++){
	int digit=num[i];
	while(digit>0){
		int curr=digit%10;
		if(ans[curr]!=1)ans[curr]=1;
		digit/=10;
	}
}
vector<int>res;
for(int i=0;i<26;i++){
	if(ans[i]==1)res.push_back(i);
}

for(int i=0;i<res.size();i++)cout<<res[i]<<" ";
}
