#include<iostream>
using namespace std;

int factorial(int num){
    int fact =1;
    for(int i=1;i<=num;i++){
        fact*=i;
    }
    return fact;
}

int nCr(int n,int r){
    if(r>n)return 0;
    if(r==0 || r==n)return 1;
    int num = factorial(n);
    int denominator = factorial(r)*factorial(n-r);
    return num/denominator;
}

int main(){
    int n=5,r=3;
    int answer = nCr(n,r);
    cout<<answer<<endl;
    return 0;

}