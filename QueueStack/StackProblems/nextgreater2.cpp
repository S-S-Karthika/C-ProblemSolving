#include<bits/stdc++.h>
using namespace std;


vector<int>brute(vector<int>&num1,vector<int>&num2){
int n= num1.size(),m=num2.size();
vector<int>result;
for(int i=0;i<n;i++){

int greater=-1;
bool found =false;
int num = num1[i];

for(int j=0;j<m;j++){
if(num2[j]==num){
	found=true;
}else if(found && num2[j]>num){
	greater=num2[j];
	break;
}
}

result.push_back(greater);
}
return result;
}


vector<int>optimal(vector<int>&num1,vector<int>&num2){
	unordered_map<int,int>mpp;
	stack<int>st;
	for(int num : num2){
		while(!st.empty()&&num>st.top()){
			mpp[st.top()]=num;
			st.pop();
		}
		st.push(num);
	}

	while(!st.empty()){
		mpp[st.top()]=-1;
		st.pop();
	}
	vector<int>result;
	for(int num : num1){
		result.push_back(mpp[num]);
	}
return result;
}

int main(){

vector<int>num1={1,2,3};
vector<int>num2={1,3,4,2};
vector<int>result1=brute(num1,num2);
vector<int>result2=optimal(num1,num2);


for(int num : result1){
cout<<num;
}

cout<<endl;

for(int num : result2){
cout<<num;
}
return 0;

}