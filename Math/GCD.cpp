#include<bits/stdc++.h>
using namespace std;

int gcd (int a,int b){
    while (b!=0)
    {
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
    
}



int main(){
    int a,b;
    a=5,b=10;
    int output = gcd(a,b);
    cout<<"The gcd is "<<output<<endl;
    cout<<"The lcm is "<<(a/output)*b<<endl;   //a/output first to prevent the over flow
    return 0;

}