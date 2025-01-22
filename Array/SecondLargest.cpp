#include<iostream>
#include<array>
#include<climits>
using namespace std;


int secondlargest(int arr[], int size){
    int largest=INT_MIN;
    int second=INT_MIN;
    for(int i=0;i<size;i++){
        if(arr[i]>largest){
            second=largest;
            largest=arr[i];
        }else if(second != largest && arr[i]>second){
            second=arr[i];
        }
    }
    return second;
}




int main(){
    int arr[5]={2,67,90,234,46};
    int size =sizeof(arr) / sizeof(arr[0]);
    int largest = secondlargest(arr,size);
    cout<<"The Second Largest Element in the Array : "<<largest<<endl;
    return 0;
}