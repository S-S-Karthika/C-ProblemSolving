#include<bits/stdc++.h>
using namespace std;

int main(){
	int n=9;
	int ospace=n/2;
	int ispace=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<ospace;j++)cout<<" ";
	
	if(i<n/2)ospace-=1;
	else ospace+=1;

	if(i==0 || i==n-1)cout<<"*";
	else{
		cout<<"*";
		for(int j=0;j<ispace;j++)cout<<" ";
		if(i<n/2)ispace+=2;
		else ispace-=2;
		cout<<"*";
	}
	cout<<endl;
   }
}