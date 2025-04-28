#include<iostream>
#include<vector>
#include<string>
using namespace std;

int occuranceAnagram(string txt ,string pat){
	int count =0;
	vector<int>patarr(26,0) , txtarr(26,0);
	int patsize = pat.size(), txtsize= txt.size();
 	if (patsize > txtsize) return 0;
	for(int i=0;i<patsize;i++){
		txtarr[txt[i]-'a']++;
		patarr[pat[i]-'a']++;
	}
	if(txtarr == patarr)count++;
	for(int i=patsize;i<txtsize;i++){
		txtarr[txt[i]-'a']++;
		txtarr[txt[i-patsize]-'a']--;
		if(txtarr == patarr)count++;
	}
	return count;
}

int main(){

	string txt = "forpforpatsatorf";
        string pat = "for";
	int count =occuranceAnagram(txt,pat);
	cout<<"The Occurance of the Anagram "<<count;
	return 0;

}