#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int  SumofSubarrayMinimum(vector<int>& nums){
        const int MOD = 1e9+7;
        int n = nums.size();
        vector<int> pse(n,-1);
        vector<int> nse(n,n);
        stack<int>s;
        long long total =0;
        
        // pervious smaller element
        for(int i=0;i<n;i++){
            while (!s.empty() && nums[i]< nums[s.top()])
            {
              s.pop();
            }
            if(!s.empty()){
              
                pse[i]=s.top();
            }
            s.push(i);
        }


        while (!s.empty())
        {
            s.pop();
        }

        // next smaller element

        for(int i=0;i < n;i++){

            while(!s.empty() && nums[i]<nums[s.top()]){
            nse[s.top()]= i;
            s.pop();
            }
            s.push(i);
         }

        // calculate the subarray sum minimum 
        
    for(int i=0;i<n;++i){
        int left = i-pse[i];
        int right = nse[i]-i;
        total+=(right*left*(long long)nums[i]) % MOD;

    }
    return (int)total;
}

int main(){
    vector<int>nums = {3,1,2,4};
    int total = SumofSubarrayMinimum(nums);
    cout<<"The Sum of the Subarray Minimum is  "<<total<<endl;
}