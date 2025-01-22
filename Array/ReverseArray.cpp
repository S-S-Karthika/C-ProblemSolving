#include<iostream>
#include<array>
#include<climits>
#include<vector>
using namespace std;


vector<int> reversed(vector<int>arr,int size ){
    int low=0;
    int high = size-1;
    while (low<=high)
    {
       int temp = arr[low];
       arr[low]=arr[high];
       arr[high]=temp;
       low++;
       high--;
    }
    return arr;
    
}


int main(){
    // vector<int>arr={2,67,90,234,46};
    // vector<int>arr={1,2,3,4,6,5};
    // vector<int>arr={1,2,3,4,5};
     for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<"  ";
    }
    vector<int>reverse = reversed(arr,arr.size());
    cout<<endl<<"Reversed Array "<<endl;
    for(int i=0;i<arr.size();i++){
        cout<<reverse[i]<<"  ";
    }
    return 0;
}