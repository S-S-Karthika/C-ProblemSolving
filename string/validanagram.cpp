#include<iostream>
#include<string>
#include<vector>
using namespace std;


bool validanagram(string s, string t){
	if(s.size()>t.size() || s.size()<t.size())return false;
	vector<int>svector(26,0);
	vector<int>tvector(26,0);
	for(int i=0;i<s.size();i++){
		svector[s[i]-'a']++;
		tvector[t[i]-'a']++;
	}
	if(svector == tvector)return true;
return false;
}

int main(){

	string s = "anagram", t = "snagaram";
	if(validanagram(s,t))cout<<"true";
	else cout<<"false";
	return 0;


}