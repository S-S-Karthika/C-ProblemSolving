#include<bits/stdc++.h>
using namespace std;

int main(){

int n=4;
cout<<"1"<<endl;

string s="1";

for(int j=1;j<n;j++){
   string res="";
   int count=1;
for(int i=1;i<s.size();i++){
	if(s[i]==s[i-1])count++;
	else{
		res+=to_string(count)+s[i-1];
		count=1;
	}
}
res+=to_string(count)+s.back();
s=res;
cout<<s<<endl;
}
return 0;
}