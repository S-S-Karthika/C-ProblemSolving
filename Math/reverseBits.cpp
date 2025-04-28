#include<iostream>
using namespace std;

unsigned int reverseBits(long n) {
    // Write your code here.
    unsigned int reverse=0;
    for(int i=0;i<32;i++){
        reverse=(reverse<<1)|(n&1);   //n&1 => took the last bit of the num 
        n>>=1; 
        cout<<reverse<< endl;
    }
    return reverse;
}

int main(){
    int n=5;
    unsigned int output = reverseBits(n);
    cout<<output<<endl;
}