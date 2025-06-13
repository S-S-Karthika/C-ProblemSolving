#include <iostream>
using namespace std;
#include <stack>
#include<vector>

vector<int> nextGreaterElement(vector<int> & nums){
   int n = nums.size();
    vector<int> nge(n, -1); // Initialize result array with -1
    stack<int> st; // Stack to store indices of array elements

    for (int i = 0; i < n; ++i) {
        // While stack is not empty and current element is greater than stack's top
        while (!st.empty() && nums[i] > nums[st.top()]) {
            nge[st.top()] = nums[i];
            st.pop();
        }
        // Push the current index onto the stack
        st.push(i);
    }

    return nge;
}


vector<int> nextSmallerElement(vector<int> & nums){
    int n = nums.size();
    vector<int> nse(n, -1); 
    stack<int> st; 

    for(int i=0;i <= n-1;i++){

        while(!st.empty() && nums[i]<nums[st.top()]){
           nse[st.top()]= nums[i];
           st.pop();
        }
        st.push(i);
    }
    return nse;
}


vector<int> nextGreaterElement2(vector<int> & nums){
   int n = nums.size();
    vector<int> nge2(n, -1); // Initialize result array with -1
    stack<int> st; // Stack to store indices of array elements

    for (int i = 0; i < 2*n; ++i) {
        // While stack is not empty and current element is greater than stack's top
        while (!st.empty() && nums[i%n] >= nums[st.top()]) {
            nge2[st.top()] = nums[i%n];
            st.pop();
        }
        // Push the current index onto the stack
        if(i<n){
           st.push(i%n);
        }
       
    }

    return nge2;
}




int main(){


// 4, 5, 2, 10, 8, 4, 5, 2, 10, 8

    vector<int> nums = {4, 5, 2, 10, 8};
    vector<int> nge = nextGreaterElement(nums);
    vector<int> nse = nextSmallerElement(nums);
    vector<int> nge2 = nextGreaterElement2(nums);

    cout << "Array: ";
    for (int num : nums) cout << num << " ";
    cout << "\nNext Greater Elements: ";
    for (int val : nge) cout << val << " ";
    cout << endl;
    cout << "\nNext Smaller Elements: ";
    for (int val : nse) cout << val << " ";
    cout << endl;
     cout << "\nNext Greater Elements two: ";
    for (int val : nge2) cout << val << " ";
    cout << endl;

    return 0;

}


