#include<bits/stdc++.h>
using namespace std;

int main(){
	string name="karthika";
	string num="0";
	num=regex_replace(num,regex("0"),"0000000000");
	string res=regex_replace(num,regex("0"),name+"\n");
	cout<<res;
}