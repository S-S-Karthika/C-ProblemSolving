#include <iostream>
using namespace std;
#include <stack>
#include<vector>

vector<int> previousGreaterElement(vector<int>nums){
    int n = nums.size();
    vector<int> pge(n, -1); 
    stack<int> st; 
    for(int i=0;i<n;i++){
        while (!st.empty() && nums[i]>st.top())
        {
           st.pop();
        }
        if(!st.empty()){
            pge[i]=st.top();
        }
        st.push(nums[i]);
    }
    return pge;
}

vector<int> previousSmallerElement(vector<int>nums){
    int n = nums.size();
    vector<int> pse(n, -1); 
    stack<int> st; 
    for(int i=0;i<n;i++){
        while (!st.empty() && nums[i]<st.top())
        {
           st.pop();
        }
        if(!st.empty()){
            pse[i]=st.top();
        }
        st.push(nums[i]);
    }
    return pse;
}

int main(){


    vector<int> nums = {4, 5, 2, 10, 8};
    vector<int> pge = previousGreaterElement(nums);
    vector<int> pse = previousSmallerElement(nums);

    cout << "Array: ";
    for (int num : nums) cout << num << " ";
    cout << endl;


    cout << "\nPrevious Greater Elements: ";
    for (int val : pge) cout << val << " ";
    cout << endl;

    cout << "\nPrevious Smaller Elements: ";
    for (int val : pse) cout << val << " ";
    cout << endl;

    return 0;

}


