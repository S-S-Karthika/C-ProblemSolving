#include<iostream>
#include<string>

using namespace std;


string removeOuterParameter(const string &s){
	string ans;
	int count=0;
	for(char ch : s){
		if(ch=='('){
			if(count>0)ans.push_back('(');
			count++;
		}else{
			count--;
			if(count>0)ans.push_back(')');
		}
	}	
return ans;
}

int main(){

	string s = "(()())(())";
	string num= removeOuterParameter(s);
	cout<<num;
	return 0;


}