#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

 vector<int> moved(vector<int>arr,int size){
    int j=0;
    for(int i=0;i<size;i++){
        if(arr[i]>0){
            arr[j]=arr[i];
            j++;
        }
    }
    while (j<size)
    {
        arr[j]=0;
        j++;
    }
    
return arr;
}


int main(){
    vector<int>arr={0,1,0,1,3,5,0,1};
    // vector<int>arr={1,2,3,4,6,5};
    // vector<int>arr={1,2,3,4,5};
     for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<"  ";
    }
     vector<int>move= moved(arr,arr.size());
    cout<<endl<<"Rotated Array "<<endl;
    for(int i=0;i<move.size();i++){
        cout<<move[i]<<"  ";
    }
    return 0;
}