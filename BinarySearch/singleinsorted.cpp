#include<iostream>
#include<vector>
using namespace std;


int single_element(vector<int>arr){
    int low =0;
    int high = arr.size();
    while(low<high){
        int mid = low+(high-low)/2;
        int length = mid-low+1;
        if(mid ==0 &&arr[mid]!=arr[mid+1]){
            return mid;
        }else{
            low = mid+1;
        }
    }
    return low;
}


int main(){
    vector<int>array = {1,1,2,3,3,4,4,8,8};
    // vector<int>array = {3,3,7,7,10,11,11};
    int single= single_element(array);
    cout<<"The single element in array is "<<arr[single];

}