// Print true if second string is a substring of first string, else print false.

#include<bits/stdc++.h>
using namespace std;

int main(){

string str1="geeksforgeeks";
string str2="geks";
int j=0,count=0;
for(int i=0;i<str1.size();i++){
	if(str1[i]==str2[j++]){
		count++;
	}else{
		if(count==str2.size()){
			cout<<"substring is find"<<endl;
			return 0;
		}
		count=0;
		j=0;
	}
}
cout<<"substring is not found";
}
