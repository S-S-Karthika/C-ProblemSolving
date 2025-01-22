#include<iostream>
#include<vector>
using namespace std;

vector<int> countingbits(int n){

    vector<int>bits(n+1,0);
    for(int i=1 ; i<=n;i++){

       bits[i]=bits[i>>1]+(i&1);
    //     bits[i]=bits[i/2]+(i&1);
       
    }
    return bits;
}

int main(){
    int n = 5;
    vector<int> answer = countingbits(n);
    for(int i=1;i<answer.size();i++){
        cout<<"The count is "<<answer[i]<<endl;
    }
   
    return 0;
}



