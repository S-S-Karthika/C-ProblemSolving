#include <iostream>
#include <vector>
using namespace std;


vector<int>rotated(vector<int>arr,int size){
    int last =arr[0];
    for(int i=0;i<size-1;i++){
        arr[i]=arr[i+1];
    }
    arr[size-1]=last;
    return arr;
}


int main(){
    vector<int>arr={2,67,90,234,46};
    // vector<int>arr={1,2,3,4,6,5};
    // vector<int>arr={1,2,3,4,5};
     for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<"  ";
    }
    vector<int>rotate = rotated(arr,arr.size());
    cout<<endl<<"Rotated Array "<<endl;
    for(int i=0;i<arr.size();i++){
        cout<<rotate[i]<<"  ";
    }
    return 0;
}