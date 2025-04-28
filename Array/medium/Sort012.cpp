#include<iostream>
#include<vector>
using namespace std;

void sortarr(vector<int>&num){
    int low=0,mid=0,high=num.size()-1;
    while(mid<high){
        if(num[mid]==2){
            swap(num[mid],num[high]);
            high--;
        }else if(num[mid]==0){
            swap(num[mid],num[low]);
            low++;
            mid++;
        }else{
            mid++;
        }
    }
}



int main(){
    vector<int>arr={1,0,2,0,1,1,2,0};
    sortarr(arr);
    for(int num:arr){
        cout<<" "<<num<<" ";
    }
    return 0;
}