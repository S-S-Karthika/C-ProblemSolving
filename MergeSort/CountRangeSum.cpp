// Input : nums=[-2,5,-1] ,lower=-2, upper=2
// Output : 3   The Ranges are [0,0],[2,2],[0,2]


#include<iostream>
using namespace std;
#include <vector>


int merge( vector<int>& arr,int low,int mid ,int high ,int lowerbound,int upperbound,int total){
    int l=low, r=high-1,sum=0;

    while(l<r) {    
        sum+=arr[l];
        if(sum >= lowerbound && sum <= upperbound){
            total+=1;
        }
    }
    return total;

}

int mergesort(vector<int>& arr,int low,int high ,int lowerbound,int upperbound,int total ){
   
   int count=0;
    if(low<high){
        int mid = low+(high-low)+1;
       count= mergesort(arr,low,mid,lowerbound, upperbound,total)+
        mergesort(arr,mid+1,high ,lowerbound, upperbound,total)+
        merge(arr,low,mid,high, lowerbound, upperbound,total);
       
    }
    
}


int main(){
    vector<int>arr={-2,5,-1};
    int lowerbound = -2;
    int upperbound = 2,total=0;
    int count = mergesort(arr,0,arr.size(),lowerbound,upperbound,total);
    cout<<"The Range is "<<count<<endl;
    return 0;

}


