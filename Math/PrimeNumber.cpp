//input :  7      10
//output: True  False

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string Prime(int value){
    int count =0;
    if(value<2){
        return"There is no prime number";
        
    }
    for(int i=2; i<=sqrt(value);i++){
        if(value%i == 0){
           return"The number is not a prime number"; 
        }
    }
    return"The number is prime number";
   
}




int main(){
    int number;
   
    cout<<"Enter a Number : ";
    cin>>number;
    string output =Prime(number);
    cout<<output<<endl;

   
}