#include<bits/stdc++.h>
using namespace std;

int main(){
int n=4;
int star=1;
for(int i=1;i<=n;i++){
	for(int j=0;j<i;j++)cout<<" ";
	for(int j=0;j<(2*n)-star;j++)cout<<"*";
	star+=2;
	cout<<endl;
}
return 0;
}