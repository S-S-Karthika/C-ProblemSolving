#include<iostream>
#include<vector>
using namespace std;


int lower(vector<int>&arr,int target){
    int low =0;
    int high= arr.size();
    while (low<high)
    {
        int mid = low+(high-low)/2;
        if(arr[mid]<target){
            
                low=mid+1;
            
        }else{
            high= mid;
        }
    }
    return low;
    
}



int upper(vector<int>&arr,int target){
    int low =0;
    int high= arr.size();
    while (low<high)
    {
        int mid = low+(high-low)/2;
        if(arr[mid]<=target){
            
                low=mid+1;
            
        }else{
            high= mid;
        }
    }
    return low;
    
}


int occurance(vector<int>&arr,int target){
    int firstoccurence = lower(arr,target);
    int lastoccurence = upper(arr,target)-1;
    if( firstoccurence<arr.size() && arr[firstoccurence] == target){
        return lastoccurence-firstoccurence+1;
    }

}


int main(){
    vector<int>arr={5,7,7,8,8,10};
    int target = 7;
    int total = occurance(arr,target);
    cout <<"The occurance of "<<target<<" is "<<total;
    return 0;
}