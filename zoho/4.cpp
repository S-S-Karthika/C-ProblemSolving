#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
vector<int>currency={2000, 500, 200, 100, 50, 20, 10, 5, 1} ;
int amount=2456;
int count=0;
vector<int>amounts(9,0);
       for(int i=0;i<9;i++){
        if(amount>=currency[i]){
            amounts[i]=amount/currency[i];
            amount=amount%currency[i];
        }
       }

for(int i=0;i<amounts.size();i++){
    if(amounts[i]!=0){
        cout<<currency[i]<<" : "<<amounts[i]<<endl;
    }
}
}
