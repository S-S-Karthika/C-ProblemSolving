#include<iostream>
#include<vector>
#include<string>
using namespace std;


void solve(int n,int open,int close,string s,vector<string>& res){
	if(open>close)return;
	if(open==0 && close==0){
		res.push_back(s);
		return;
	}
	if(open>0){
		s.push_back('(');
		solve(n,open-1,close,s,res);
		s.pop_back();
	}
	if(close>0){
		s.push_back(')');
		solve(n,open,close-1,s,res);
		s.pop_back();
	}
	

}

vector<string>generate(int n){
if(n<=0)return {};
vector<string>res;
solve(n,n,n,"",res);
return res;
}


int main(){

vector<string>ans=generate(3);
for(string s:ans){
	cout<<s<<" ";
}

}