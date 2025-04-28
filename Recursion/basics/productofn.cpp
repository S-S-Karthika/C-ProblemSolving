#include<iostream>
using namespace std;

int product(int n){
	if(n==0)return 1;
	return n*product(n-1);
}

int main(){
	int n;
	cout<<"Enter the number for product "<<endl;
	cin>>n;
	if(n==0){
	   cout<<0;	
           return n;
	}
	cout<<product(n);
	return 0;
}