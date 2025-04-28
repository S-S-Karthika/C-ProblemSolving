#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

int longestSubstring(string s ){
	vector<int>occur(26,0);
	int start=0,n=s.size(),maxlen=-1;
	for(int i=0;i<n;i++){
            while(occur[s[i]-'a']){
		occur[s[start]-'a']--;
		start++;
	    }
	    occur[s[i]-'a']++;
	    maxlen=max(maxlen,i-start+1);

	}
return maxlen;
}

int main(){

	string s = "abcdefghijabcbb";
	int length =longestSubstring(s);
	cout<<"The Longest Substring with Distint Uniques "<<length;
	return 0;

}