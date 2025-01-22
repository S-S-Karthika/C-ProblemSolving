#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;


vector<int>intersection(vector<int>&arr1,vector<int>&arr2){
    int n1=arr1.size();
    int n2=arr2.size();
    int i=0,j=0;
    vector<int>answer;
    while(i<n1 && j<n2){
        if(arr1[i]==arr2[j]){
            answer.push_back(arr1[i]);
            i++;
            j++;
        }else if(arr1[i]<arr2[j]){
            answer.push_back(arr1[i]);
            i++;
        }else{
            answer.push_back(arr2[j]);
            j++;
        }
    }
    while(i<n1){
        answer.push_back(arr1[i]);
        i++;
    }
    while (j<n2)
    {
        answer.push_back(arr2[j]);
        j++;
    }

    return answer;
    
}


int main(){
    vector<int>arr1={1,4,6,7,8,9};
    vector<int>arr2={2,3,5,6,7,9};
    vector<int>answer=intersection(arr1,arr2);
    for(auto & num : answer){
        cout<<num<<" ";
    }
}