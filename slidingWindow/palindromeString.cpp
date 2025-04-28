#include<iostream>
#include<vector>
#include<string>
using namespace std;

int palindromeString(string s1 ,string s2){

int k=s1.size();
vector<int>s1arr(26,0) , s2arr(26,0);


for(int i=0;i<k;i++){
 s1arr[s1[i]-'a']++;
 s2arr[s2[i]-'a']++;	
}
if(s1arr == s2arr)return 1;
for(int i=k;i<s2.size();i++){
	s2arr[s2[i]-'a']++;
	s2arr[s2[i-k]-'a']--;
	if(s1arr == s2arr)return 1;
}
return 0;
}

int main(){

	string txt = "ab";
        string pat = "eidsibsa";
	int count =palindromeString(txt,pat);
	cout<<"The Palindrome of the String "<<count;
	return 0;

}