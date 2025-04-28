#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool ispalindrome(string s, int low,int high){

	while(low<=high){

		if(s[low]!=s[high]){
			return false;
		}
		low++;
		high--;
	}
	return true;

}

void palindromesequence(int index,string s,vector<string>&curr,vector<vector<string>>&result){

	if(index==s.length()){
		result.push_back(curr);
		return;
	}
	for(int i=index;i<s.length();i++){
		if(ispalindrome(s,index,i)){
			curr.push_back(s.substr(index,i-index+1));
			palindromesequence(i+1,s,curr,result);
			curr.pop_back();

		}
	}

}



int main(){

 string s="aabb";
 vector<string>curr;
 vector<vector<string>>result;
 palindromesequence(0,s,curr,result);
 for(auto& subset : result)
	{
		cout<<"[ ";
		for(string& num:subset){
			cout<<num<<" ";
		}
		cout<<" ]";
	}
 return 0;


}