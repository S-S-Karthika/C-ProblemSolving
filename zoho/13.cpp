//Find the prime number in the given range. (test cases: interval is negative in range)

#include<bits/stdc++.h>
using namespace std;


bool isprime(int num){
if(num<=0)return false;
for(int i=2;i*i<=num;i++){
	if(num%i==0)return false;
}
return true;
}

int main(){

int num1=-23;
int num2=41;
if (num1 > num2) swap(num1, num2);
for(int i=num1;i<=num2;i++){
if(isprime(i))cout<<i<<" ";
}
return 0;
}