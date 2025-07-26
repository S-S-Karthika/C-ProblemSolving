// TWISTED PRIME NUMBER

#include<bits/stdc++.h>
using namespace std;


bool isprime(int num){
for(int i=2;i*i<=num;i++){
	if(num%i==0)return false;
}
return true;
}

int main(){

int num=23;
int copy=num;
if(!isprime(num)){
	cout<<"given num is not a prime";
	return 0;
}
int twist=0;
while(num>0){
	int digit=num%10;
	twist=(twist*10)+digit;
	num/=10;
}

if(!isprime(twist)){
	cout<<"twist num is not a prime";
	return 0;
}
cout<<"both are prime "<<copy<<" "<<twist;
return 0;
}