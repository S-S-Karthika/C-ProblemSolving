#include<iostream>
#include<vector>
using namespace std;

void rotated(vector<int>&arr,int n){
int first=arr[n-1];
for(int i=n;i>0;i--){
arr[i]=arr[i-1];
}
arr[0]=first;
}


int main(){
    vector<int>arr={2,67,90,234,46};
    // vector<int>arr={1,2,3,4,6,5};
    // vector<int>arr={1,2,3,4,5};
     for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<"  ";
    }
    rotated(arr,arr.size());
    cout<<endl<<"Rotated Array "<<endl;
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<"  ";
    }
    return 0;
}