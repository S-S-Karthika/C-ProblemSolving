#include<iostream>
#include<vector>
#include<climits>
#include<unordered_map>
using namespace std;


int subarrayZero(vector<int>& arr){
    int maxLen = INT_MIN;
    int sum=0,count=0;
    unordered_map<int,int>total;
    for(int i=0;i<arr.size();i++){
        sum += arr[i] ;
        if(sum == 0){
            maxLen = i +1;
        }
        if(total.find(sum)!= total.end()){
            count = i - total[sum];
            maxLen = max(maxLen,count);
        }else{
             total[sum]=i;
        }
        
        
    }
    return maxLen;
}



int main(){
    // vector<int>arr={2,4,-4,8,-7,1,-2};
     vector<int>arr={1,2,-3,3,1,-4,2,1};
    //  vector<int>arr={1,2,-3,3,-3,1,-4,2,1};
    // vector<int>arr={1,2,3,1,-4,2,1};
    int sumZero = subarrayZero(arr);
    cout<<"The Largest Subarray Sum "<<sumZero<<endl;
    return 0;
}