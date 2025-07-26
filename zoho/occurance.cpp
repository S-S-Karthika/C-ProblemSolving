#include<bits/stdc++.h>
using namespace std;


int main(){

string s="3[b2[ca]]";

stack<int>num;
stack<string>st;
string ans="";
int nums=0;

for(int i=0;i<s.size();i++){
if(isdigit(s[i])){
	nums=nums*10+(s[i]-'0');
}else if(s[i]=='['){
	num.push(nums);
	st.push(ans);
	nums=0;
	ans="";
}else if(s[i]==']'){
	string temp=st.top();
	st.pop();
	int count=num.top();
	num.pop();
	while(count--)temp+=ans;
	ans=temp;
}else{
	ans+=s[i];
}

}
cout<<ans;
}