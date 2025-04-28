#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>arr={1,1,2,2,4,4,3,3,5};
    int single=0;
    for(int num : arr){
        single^=num;
    }
    cout<<"The single number is "<<single<<endl;
    return 0;
}