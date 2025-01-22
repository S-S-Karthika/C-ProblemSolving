#include<iostream>
#include<array>
#include<climits>
using namespace std;

bool sorted(int arr[],int size){
    for(int i=0;i<size;i++){
        if(arr[i]>arr[i+1]){
            return false;
        }
    }
    return true;
}



int main(){
    // int arr[5]={2,67,90,234,46};
    // int arr[6]={1,2,3,4,6,5};
    int arr[5]={1,2,3,4,5};
    int size =sizeof(arr) / sizeof(arr[0]);
    bool sort = sorted(arr,size);
    cout<<"The Array is sorted or not : "<<sort<<endl;
    return 0;
}