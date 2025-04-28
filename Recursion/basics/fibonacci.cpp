#include<iostream>
using namespace std;

int findfibonacci(int n){
	if(n<=1 )return n;
	return findfibonacci(n-1)+findfibonacci(n-2);
}

int main(){
	int n;
	cout<<"Enter the number for fibonaci"<<endl;
	cin>>n;
	cout<<"Fibonacci Series"<<endl;
	for(int i=0;i<=n;i++){
		cout<<findfibonacci(i)<<" ";
	}
	return 0;
}