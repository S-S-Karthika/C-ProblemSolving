#include<iostream>
#include<vector>
using namespace std;

int findelement(vector<int>nums, int target){
    int low=0,high=nums.size()-1;
    while (low<=high)
    {
        int mid = low+(high-low)/2;
        if(nums[mid]==target){
            return mid;
        }else if(nums[mid]>target && nums[low]>target){
            low=mid+1;
        }else{
            high = mid;
        }
    }
    return -1;
}



int main(){
    // vector<int>nums={4,5,6,7,0,1,2};
    vector<int>nums={0};

    int target = 0;
    int result = findelement(nums,target);
    cout<<"The element is at index "<<result;
}