#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


string reversewords(const string &s){

	string ans="";
	for(int i=s.size()-1;i>=0;i--){
		int num=s[i]-'0';
		if((s[i]-'0')%2!=0){
			return s.substr(0,i+1);
		}
	}
return "";
}

int main(){

	string s = "4207";
	string num =reversewords(s);
	cout<<num;
	return 0;


}