//Transform String

#include <bits/stdc++.h>
using namespace std;

int main(){


string str1="xxoxoox";
int n=str1.size(),j=0,count=0;

while(j<n){
	if(str1[j]=='x'){
		count++;
		j+=3;
	}else{
		j++;
	}
}
cout<<count;
}