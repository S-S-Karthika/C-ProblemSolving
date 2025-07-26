#include<bits/stdc++.h>
using namespace std;

int main(){

int n=5,left=1,right=n;
for(int i=1;i<=n;i++){
	for(int j=0;j<n-i;j++)cout<<" ";
	for(int j=n-i;j<i+2;j++)cout<<abs(j-n+2);
cout<<endl;
}
}