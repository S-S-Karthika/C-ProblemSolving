#include<iostream>
using namespace std;

double pow(double num, int x){
	if(x==0)return 1;
	if(x<0)return 1/pow(num,-x);
	double half=pow(num,x/2);
	if(x%2 ==0)return half*half;
	else return num*half*half; 
	
}

int main(){
	double num;
	int x;
	cout<<"Enter the number for Power"<<endl;
	cin>>num;
	cout<<"Enter the Exponential"<<endl;
	cin>>x;
	cout<<pow(num,x);
	return 0;
}