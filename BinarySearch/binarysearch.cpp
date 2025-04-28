#include<iostream>
using namespace std;
#include<vector>

bool binarysearch(vector<int>array,int num){
    int size = array.size();
    int low =0, high = size-1;
    
    while(low<=high){
        int mid = low +(high - low)/2;
        if(array[mid]== num){
            return true;
        }else if(array[mid]<num){
            low = mid+1;

        }else{
            high = mid-1;
        }
    }
    return false;
}





int main(){
    int findnum = 27;
    vector<int>arr={12,23,34,45,67};
    string result = binarysearch(arr,findnum) ? "found" : "not found";
    cout<< "The element in the array is "<< result;
    return 0;
}