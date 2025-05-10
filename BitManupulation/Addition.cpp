#include<iostream>
using namespace std;

int add(int a ,int b){
    while (b!=0)
    {
        int carry= (a&b)<<1;  //if not shift 1 we calculate the same number over again
        a=a^b;   //add two numbers without carry
        b=carry;  //store the carry to add in ans 'a'
        cout<<"a"<<a<<"  ";
        cout<<"b"<<b<<"  ";
        cout<<"carry"<<carry<<" "<<endl;
        
    }
    return a;
}


int main(){
    int a=10;
    int b=10;
    cout<<"The addition of two number is "<<add(a,b)<<endl;
    return 0;
}