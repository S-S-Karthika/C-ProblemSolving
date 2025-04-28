#include<iostream>
#include<vector>
using namespace std;


int minarray(vector<int>&arr){
    int low=0;
    int high=arr.size();
    while (low<high)
    {


        if(arr[0]<arr[high]){
            return low;
        }
        int mid = low+(high-low)/2;
        if(arr[mid]>arr[mid+1] ){
           return mid+1;
        }
        
        if( arr[mid]<arr[mid+1] && arr[mid]>arr[mid-1]){
            return mid;
        }
            
        if(arr[mid]>arr[low] && arr[mid]>arr[high]){
                low=mid+1;
        }else{
                high = mid-1;
        }
        
    }
    
}


int main(){
    vector<int>array={1,2,3,4,5};
    // vector<int>array={4,5,6,7,0,1,2};
    // vector<int>array={3,4,5,1,2};
    int minimum = minarray(array);
    cout<<"The minimum in the array is "<<array[minimum];
}