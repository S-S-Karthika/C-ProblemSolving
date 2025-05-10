#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;


int sortchar(const string &s){
	int low=0,n=s.size(),ans=0;
	unordered_map<char,int>mpp;
	for(int high =0;high<n;high++){
		mpp[s[high]]++;
		while(mpp['a']>0 && mpp['b']>0 ){
			ans+=(n-high);
			mpp[s[low]]--;
			low++;
		}
	}
return ans;

}

int main(){

	string s = "aabbb";
	
	int  ans= sortchar(s);
	cout<<ans;
	return 0;


}