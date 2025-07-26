#include<iostream>
using namespace std;


int main(){

int n=10;
int i=0;
n=n<<i;
if((n&1) == 0)cout<<"It is not a set bit";
else cout<<"it is set bit";

}