#include<iostream>
#include<array>
#include<climits>
#include<vector>
using namespace std;


vector<char> reversed(vector<char>arr,int size ){
    int low=0;
    int high = size-1;
    while (low<=high)
    {
       char temp = arr[low];
       arr[low]=arr[high];
       arr[high]=temp;
       low++;
       high--;
    }
    return arr;
    
}


int main(){
    
    vector<char>arr={'q','w','e','r','t'};
     for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<"  ";
    }
    vector<char>reverse = reversed(arr,arr.size());
    cout<<endl<<"Reversed Array "<<endl;
    for(int i=0;i<arr.size();i++){
        cout<<reverse[i]<<"  ";
    }
    return 0;
}