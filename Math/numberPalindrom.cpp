#include<iostream>
using namespace std;

int reversePalindrome(int num){
    int reversed=0;
    while(num!=0){
        int digit = num%10;
        reversed= reversed*10 + digit;
        num/=10;
    }
    return reversed;
}

int main (){
    int num =1221;
    int reverse= reversePalindrome(num);
   if(reverse == num ){
        cout<<"The num is palindrome";
   }else{
    cout<<"The num is not palindrome";
   }
}