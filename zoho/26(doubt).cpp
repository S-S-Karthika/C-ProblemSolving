//Decode a string recursively encoded as count followed by substring.

#include <bits/stdc++.h>
using namespace std;



int main(){
string s="3[b2[ac]]";
string res="";
stack<int>num;
stack<char>st;
for(char ch:s){
	if(isdigit(ch)){
		int count=(count*10)+ch-'0';
	}else if(ch=='['){
		num.push_back(count);
		count=0;
		st.push_back(res);
		res="";
	}else if(ch=='['){
		string temp="";
		int occur=num.top();
		num.pop();
		string curr=st.top();
		st.pop();
		while(occur--)temp+=curr;
		res+=temp;
	}else{
		res+=ch;
	}
}
}


