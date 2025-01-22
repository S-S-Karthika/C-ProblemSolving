#include<iostream>
using namespace std;

int main(){
    int n =3;
    
    cout<<(n&(n-1)?"false":"true")<<endl;
    return 0;
}