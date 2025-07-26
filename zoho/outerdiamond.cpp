#include<bits/stdc++.h>
using namespace std;

int main(){
	int n=11;
	int right=(n+1)/2;
	int left=(n+1)/2;
	
	for(int i=0;i<n/2;i++){
		for(int j=i;j<right;j++)cout<<"*";
		for(int j=0;j<i*2;j++)cout<<" ";
		for(int j=i;j<right;j++)cout<<"*";
		cout<<endl;
	}
	//secondhalf
	for(int i=n/2;i>=0;i--){
		for(int j=i;j<right;j++)cout<<"*";
		for(int j=0;j<i*2;j++)cout<<" ";
		for(int j=i;j<right;j++)cout<<"*";
		cout<<endl;
	}
}