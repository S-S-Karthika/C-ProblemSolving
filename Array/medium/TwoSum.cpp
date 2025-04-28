#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int>twoSum(vector<int>& arr,int target){
    unordered_map<int,int>sum;
    for(int i=0;i<arr.size();i++){
        int total=target-arr[i];
        if(sum.find(total)!=sum.end()){
           return{sum[total],i};
        }
        sum[arr[i]]=i;
    }
    return {};
}

int main(){
    vector<int>arr={2,11,15,7};
    int target=9;
    vector<int>result=twoSum(arr,target);  
    if(!result.empty()){
        cout<<result[0]<<"  "<<result[1]<<endl;
    } 
    
    return 0;

}