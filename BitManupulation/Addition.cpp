#include<iostream>
using namespace std;

int add(int a ,int b){
    while (b!=0)
    {
        int carry= (a&b)<<1;
        a=a^b;
        b=carry;
    }
    return a;
}


int main(){
    int a=19;
    int b=21;
    cout<<"The addition of two number is "<<add(a,b)<<endl;
    return 0;
}