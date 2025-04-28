#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

int longestSubstring(string s ,int k){
	unordered_map<char,int>occur;
	int start=0,n=s.size(),maxlen=-1;
	for(int i=0;i<n;i++){
		occur[s[i]]++;
		while(occur.size()>k){
			occur[s[start]]--;
			if(occur[s[start]]==0)occur.erase(s[start]);
			start++;
		}
		if(occur.size()==k){
			maxlen = max(maxlen,i-start+1);
		}
	}
return maxlen;
}

int main(){

	string s = "aabacbebebe";
	//string s = "aaaabbbbbbbb";
        int k =3;
	int count =longestSubstring(s,k);
	cout<<"The Longest Substring with K Uniques "<<count;
	return 0;

}