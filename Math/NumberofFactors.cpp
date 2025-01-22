// input : n=5    n=25
// output : 2      3

// explanation : 1*5=5 , 5*1=5 ;
// explanation : 1*25=25 , 25*1=25, 5*5=25 ;


#include<bits/stdc++.h>
using namespace std;

int factor(int value){
    int count =0;
    for(int i=1 ; i<=sqrt(value);i++){
        if(value%i == 0){
            if(value/i == i){
                count++;
            }
            else{
              count+=2;
            }
        }
    }
    return count;
}



int main(){
    int n ;
    cout<<"The input value for the Factor is ";
    cin>> n ;
    cout<<"The number of factor is " << factor(n) <<endl;
}



