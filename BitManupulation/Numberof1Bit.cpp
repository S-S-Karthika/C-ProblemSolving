#include<iostream>
using namespace std;

int main(){
    int n = 3;
    cout<<" The input is "<<n<<endl;
    int count =0;
    while (n)
    {
       count += (n&1);
       n>>=1;
    }
    cout<<"The count is "<<count<<endl;
    
    return 0;
    
}