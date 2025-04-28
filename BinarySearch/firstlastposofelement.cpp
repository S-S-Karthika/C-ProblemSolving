#include<iostream>
#include<vector>
using namespace std;

int lowerbound(vector<int>&arr,int target){
    int low = 0, high = arr.size() - 1, res = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target) {
            if (arr[mid] == target) res = mid;  // Store possible first occurrence
            high = mid - 1; // Move left
        } else {
            low = mid + 1;
        }
    }
    return res;
}


int upperbound(vector<int>&arr,int target){
    int low = 0, high = arr.size() - 1, res = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= target) {
            if (arr[mid] == target) res = mid; // Store possible last occurrence
            low = mid + 1; // Move right
        } else {
            high = mid - 1;
        }
    }
    return res;
}

vector<int>bounds(vector<int>&arr,int target){
    vector<int>ans(2,-1);
    ans[0]=lowerbound(arr,target);
        if(ans[0]==-1){
            ans[1]==-1;
            return ans;
        }else{
            ans[1]=upperbound(arr,target);
        }
}


int main(){
    vector<int>arr={5,7,7,8,8,10};
    int target = 6;
    vector<int>ans=bounds(arr,target);
    for(int arr : ans){
        cout<<arr<<" ,";
    }

}