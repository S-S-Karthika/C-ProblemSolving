#include<iostream>
#include<string>
using namespace std;

bool palindrome (string s, int i ,int n){
	if(i>=n)return true;
	if(s[i]!=s[n])return false;
 	return palindrome(s,i+1,n-1);
}

int main(){
	string s;
	cout <<"Enter the string to check palindrome "<<endl;
	cin >>s;
	int i=0,n=s.size();
	cout << palindrome(s,i,n-1);
	return 0;
}