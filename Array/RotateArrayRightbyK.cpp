#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

void rotated(vector<int>&arr,int size,int k){
    k=k%size;
    reverse(arr.begin()+k,arr.end());
    reverse(arr.begin(),arr.begin()+k);
    reverse(arr.begin(),arr.end());
   
}


int main(){
    vector<int>arr={2,67,90,234,46};
    // vector<int>arr={1,2,3,4,6,5};
    // vector<int>arr={1,2,3,4,5};
    int k =2;
     for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<"  ";
    }
     rotated(arr,arr.size(),k);
    cout<<endl<<"Rotated Array "<<endl;
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<"  ";
    }
    return 0;
}