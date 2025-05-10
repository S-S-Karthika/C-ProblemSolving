#include<iostream>
#include<string>
#include<vector>
using namespace std;


string longestprefix(const vector<string> &s){

	if(s.empty())return "";
	string prefix=s[0];
	int n=s.size();
	for(int i=1;i<n;i++){
		while(s[i].find(prefix)!=0){
			prefix=prefix.substr(0,prefix.size()-1);
			if(prefix.empty())return "";
		}
	}
	return prefix;
}

int main(){

	vector<string>strs={"flower","flow","eeight"};
	string num =longestprefix(strs);
	cout<<num;
	return 0;


}