#include<iostream>
#include<string>
#include<vector>
using namespace std;


string longestpalindrome(string s){
	int n=s.size();
	int low=0,high=0,start=0,maxlen=1;
	for(int i=0;i<n;i++){
		//for even
		low=i,high=i+1;
		while(low>=0 && high<=n && s[low]==s[high]){
			if(high-low+1>maxlen){
				start=low;
				maxlen=high-low+1;
			}
			low--,high++;
		}

		//odd palindrome 
		low=i,high=i;
		while(low>=0 && high<=n && s[low]==s[high]){
			if(high-low+1>maxlen){
				start=low;
				maxlen=high-low+1;
			}
			low--,high++;
		}

		
	}
return s.substr(start,maxlen);
}

int main(){

	string s="babaaaaaab";
	string ans= longestpalindrome(s);
	cout<<ans;
	return 0;
}