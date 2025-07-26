#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int  SumofSubarrayMaximum(vector<int>& nums){
        const int MOD = 1e9+7;
        int n = nums.size();
        vector<int> pge(n,-1);
        vector<int> nge(n,n);
        stack<int>s;
        long long total =0;
        
        // pervious greater element
        for(int i=0;i<n;i++){
            while (!s.empty() && nums[s.top()]<=nums[i])
            {
              s.pop();
            }
            if(!s.empty()){
                pge[i]=s.top();
            }
            s.push(i);
        }


        while (!s.empty())
        {
            s.pop();
        }

        // next greater element

        for(int i=0;i < n;i++){

            while(!s.empty() && nums[i]>nums[s.top()]){
                nge[s.top()]= i;
                s.pop();
            }
            s.push(i);
         }

        // calculate the subarray sum minimum 
        
    for(int i=0;i<n;++i){
        int left = i-pge[i];
        int right = nge[i]-i;
        total+=(right*left*(long long)nums[i]) % MOD;

    }
    return (int)total;
}

int main(){
    vector<int>nums = {3,1,2,4};
    int total = SumofSubarrayMaximum(nums);
    cout<<"The Sum of the Subarray Maximum is  "<<total<<endl;
}