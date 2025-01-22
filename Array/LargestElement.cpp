#include<iostream>
#include<array>
#include<climits>
using namespace std;

int largestElement(int arr[],int size){
    int max=INT_MIN;
    for(int i=0;i<size;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

int main(){
    int arr[5]={2,67,9000,234,46};
    int size =sizeof(arr) / sizeof(arr[0]);
    int largest = largestElement(arr,size);
    cout<<"The Largest Element in the Array : "<<largest<<endl;
    return 0;
}