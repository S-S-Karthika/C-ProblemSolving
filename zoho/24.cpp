//Find whether the given number is palindrome or not. Don’t use arrays or strings

#include <bits/stdc++.h>
using namespace std;



int main(){
int num=2334332;
int copy=num;
int reverse=0;
while(num>0){
	reverse=(reverse*10)+num%10;
	num/=10;
}

cout<<reverse<<endl;
if(copy==reverse)cout<<"IT is a palindrome"<<endl;
else cout<<"not palindrome";
}


