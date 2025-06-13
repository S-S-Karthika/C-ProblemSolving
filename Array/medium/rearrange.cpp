#include <iostream>
#include <vector>
using namespace std;

void rearrangeInPlace(vector<int>& arr) {
    int n = arr.size();

    // Step 1: Partition - move all negative numbers to the end
    int i = 0, j = 0;
    while (j < n) {
        if (arr[j] >= 0) {
            swap(arr[i], arr[j]);
            i++;
        }
        j++;
    }

    // Now arr[0 to i-1] are positive, arr[i to n-1] are negative
    int pos = 0, neg = i;

    // Step 2: Rearrange alternately
    while (pos < neg && neg < n && arr[pos] >= 0) {
        swap(arr[pos], arr[neg]);
        pos += 2;
        neg++;
    }
}

vector<int> better(vector<int>nums,int n){
	vector<int>res(n,0);
	int pos=0,neg=1;
	for(int i=0;i<n;i++){
		if(nums[i]>0){
			res[pos]=nums[i];
			pos+=2;
		}else{
			res[neg]=nums[i];
			neg+=2;
		}
	}
return res;
}


int main() {
    vector<int> arr = {1, 2, -4, -5, 3, -6, 7, -8};
    
    rearrangeInPlace(arr);
    
    for (int num : arr) cout << num << " ";
    return 0;
}
