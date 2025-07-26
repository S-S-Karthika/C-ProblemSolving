//Find the extra element and its index
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr1 = {1, 3, 5, 8, 9, 2};
    vector<int> arr2 = {3, 1, 5, 9, 8};

  
    vector<int> original = arr1;

    // Sort both arrays
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    int extra = arr1.back();  
    for(int i = 0; i < arr2.size(); i++) {
        if(arr1[i] != arr2[i]) {
            extra = arr1[i];
            break;
        }
    }

  
    for(int i = 0; i < original.size(); i++) {
        if(original[i] == extra) {
            cout << "Extra element: " << extra << ", at index: " << i << endl;
            return 0;
        }
    }

    return 0;
}
