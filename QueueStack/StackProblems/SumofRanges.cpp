#include <iostream>
#include <stack>
#include <vector>
using namespace std;




long long minsumsubarray(vector<int>& arr){
       
        int n=arr.size();
        vector<int>pse(n,-1),nse(n,n);
        stack<int>st;
        //pse
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                pse[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty())st.pop();
        //nse
        for(int i=0;i<n;i++){
             while(!st.empty() && arr[i]<=arr[st.top()]){
                nse[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }

        long long total=0;
        for(int i=0;i<n;i++){
            long long left=i-pse[i];
            long long right=nse[i]-i;
            total += (long long)arr[i]*left*right;
        }
        return total;
    }

long long maxsumsubarray(vector<int>& arr){
        int MOD=1e9+7;
        int n=arr.size();
        vector<int>pge(n,-1),nge(n,n);
        stack<int>st;
        //pge
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                pge[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty())st.pop();
        //nge
        for(int i=0;i<n;i++){
             while(!st.empty() && arr[i]>=arr[st.top()]){
                nge[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }

        long long total=0;
        for(int i=0;i<n;i++){
            long long left=i-pge[i];
            long long right=nge[i]-i;
            total += (long long)arr[i]*left*right;
        }
        return total;
    }


long long subArrayRanges(vector<int>& nums) {
        
        long long minSum = minsumsubarray(nums);
        long long maxSum = maxsumsubarray(nums);
        return (maxSum - minSum);
    }


int main(){
    vector<int>nums = {3,1,2,4};
    int total = subArrayRanges(nums);
    cout<<"The Sum of the Subarray Maximum is  "<<total<<endl;
}