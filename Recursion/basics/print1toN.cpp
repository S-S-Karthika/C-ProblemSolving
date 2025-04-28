#include <iostream>
using namespace std;

void print1toN(int n){
    if(n==0)return;
    cout<<n<<" ";
    print1toN(n-1);
}


     int main(){
        int n;
        cout<<"Enter a Number : "<<endl;
        cin>> n;
        print1toN(n);
        return 0;
     }
