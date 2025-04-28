//Three sum

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<int> threeSum(vector<int> arr, int target) {
    int n = arr.size();
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum == target) {
                    return {i, j, k};                  }
            }
        }
    }
    return {-1, -1, -1};
}


//------------------------------------------------------------------------------------------------


vector<vector<int>> triplet(int n, vector<int> &arr) {
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        if (i != 0 && arr[i] == arr[i - 1]) continue;
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0) {
                j++;
            }
            else if (sum > 0) {
                k--;
            }
            else {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (j < k && arr[j] == arr[j - 1]) j++;
                while (j < k && arr[k] == arr[k + 1]) k--;
            }
        }
    }
    return ans;
}
		


int main(){

vector<int>arr={1,2,3,4,5,6,-6,0,-3};
int target =12,n=arr.size();
vector<int>ans = threeSum(arr,target);
vector<vector<int>> ans1 = triplet(n, arr);


cout<<arr[ans[0]]<<endl;
cout<<arr[ans[1]]<<endl;
cout<<arr[ans[2]]<<endl;
cout<<endl;
for (auto subset : ans1) {
    for (int num : subset) {
        cout << num << " ";
    }
    cout << endl;
}
return 0;

}