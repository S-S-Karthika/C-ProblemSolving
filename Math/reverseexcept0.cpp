#include<iostream>
using namespace std;


int reverseexceptzero(int num){
    int reversed =0;
    while(num>0){
        int digit = num%10;
        reversed=digit+reversed*10;
        num/=10;
        if(digit == 0 && reversed == 0){
            continue;
        } 
        
    }
    return reversed;

}


int main(){
    int num = 10400;
    int reverse = reverseexceptzero(num);
    cout<<"The Reverse is "<<reverse<<endl;
}