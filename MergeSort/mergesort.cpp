#include<iostream>
using namespace std;
#include<vector>

vector<int>merge(vector<int>& array,int low,int mid ,int high){
    if(low>=high)return array;
    int n1=mid-low+1;
    int n2=high-mid;
    vector<int>left(n1);
    vector<int>right(n2);
    for(int i=0;i<n1;i++){
        left[i]=array[low+i];
    }
    for(int i=0;i<n2;i++){
        right[i]=array[mid+i+1];
    }
    int i=0,j=0,k=low;
    while (i<n1 && j<n2)
    {
        if(left[i]<=right[j]){
            array[k++]=left[i++];
        }else{
            array[k++]=right[j++];
        }
    }
    while (i<n1)
    {
       array[k++]=left[i++];
    }
    while (j<n2)
    {
       array[k++]=right[j++];
    }

    return array;

}



vector<int>mergesort(vector<int>& array,int low , int high){
    if(low<high){
        int mid = low+(high-low)/2;
        mergesort(array,low,mid);
        mergesort(array,mid+1,high);
        return merge(array,low,mid,high);
    }
}


vector<int>merging(vector<int>& array){
    int low =0;
    int high = array.size()-1;  
    return mergesort(array,low,high);
}


int main(){
    // vector<int>arr={7,4,0,6,2,7};
    // vector<int>arr={1,2,3,4,5,6};
    vector<int>arr={863,9086,5372673,0000,456};
    vector<int> ans = merging(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" , ";
    }
}