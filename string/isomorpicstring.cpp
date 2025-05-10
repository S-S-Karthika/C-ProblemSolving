#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;


bool isomorpicstring(string s,string t){
	int ssize=s.size(),tsize=t.size();
	unordered_map<char,char>smap,tmap;
	if(ssize!=tsize)return 0;
	for(int i=0;i<tsize;i++){
		if(smap.find(s[i])!=smap.end()){
			if(smap[s[i]]!=t[i])return 0;
		}else if(tmap.find(t[i])!=tmap.end()){
			if(tmap[t[i]]!=s[i])return 0;

		}
	 smap[s[i]]=t[i];
	 tmap[t[i]]=s[i];
	}
	return true;
}

int main(){

	string s="egg",t="add";
	if(isomorpicstring(s,t)) cout<<"true";
	else cout<<"false";
	return 0;


}