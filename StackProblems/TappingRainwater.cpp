#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>


int tappingwater(vector <int>& nums){
    int size = nums.size();
    if(size==0)return 0;
     int l=0,r=size-1;
     int total=0;
     int lmax=0,rmax=0;
     while (l<=r)
     {
        if(nums[l]<=nums[r] ){
            if(nums[l]>=lmax){
                lmax=nums[l];
            }else{
                total+=lmax-nums[l];
            }
            l++;
        }else{
             if(nums[r]>=rmax){
                rmax=nums[r];
            }else{
                total+=rmax-nums[r];
            }
             r--;
        }
       
     }
     return total;
     
}


int main(){
    vector <int> nums={0,1,0,2,1,0,1,3,2,1,2,1};
    int totalheight =  tappingwater(nums);
    cout<<"The total height to save water "<<totalheight<<endl;
}