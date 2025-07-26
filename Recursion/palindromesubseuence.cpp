#include<iostream>
#include<vector>
#include<string>
using namespace std;


//method 1
// Using string to store the palindrome subsequence
// This method finds all palindromic subsequences of a given string using recursion and backtracking.

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


// Method 2
// Using vector<char> to store the characters of the palindrome subsequence

bool ispalindrome(vector<char>&arr,int low,int high){

	while(low<high){
		if(arr[low]!=arr[high])return false;
		low++;
		high--;
	}
return true;
}

void palindromesubsequence(int index,string &s,vector<vector<char>>&res,vector<char>&curr){

	if(index==s.size()){
		if(ispalindrome(curr,0,curr.size()-1) && !curr.empty()){
			res.push_back(curr);
		}
		return;
	}
	curr.push_back(s[index]);
	palindromesubsequence(index+1,s,res,curr);
	curr.pop_back();
	palindromesubsequence(index+1,s,res,curr);


}

bool ispalin(string s ,int first,int last){

while(first<last){
	if(s[first]!=s[last])return false;
	first++;
	last--;
}
return true;
}

void palindromesequence3(int pos ,string input,vector<string>& curr,string s){
	
	if(pos==input.size()){
		if(ispalin(s,0,s.size()-1)){
		curr.push_back(s);
		
	}
		return;
	}
	
	s.push_back(input[pos]);
	palindromesequence3(pos+1,input,curr,s);
	s.pop_back();
	palindromesequence3(pos+1,input,curr,s);
	
}

int main(){

 string s="aabb";
 vector<string>curr;
 vector<vector<string>>result;
 palindromesequence(0,s,curr,result);  //method1
 for(auto& subset : result)
	{
		cout<<"[ ";
		for(string& num:subset){
			cout<<num<<" ";
		}
		cout<<" ]";
	}
 palindromesubsequence(0,s,result,curr);  //method2
 for(auto& subset : result)
	{
		cout<<"[ ";
		for(string& num:subset){
			cout<<num<<" ";
		}
		cout<<" ]";
	}


	//method 3
	 

 palindromesequence3(0,s,curr,""); 

		for(string& num:curr){
			cout<<num<<" ";
		}
 return 0;


}