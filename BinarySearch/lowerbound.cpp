#include <iostream>
#include <vector>
using namespace std;

int lowerbound(vector<int>& arr, int num) {
    int low = 0, high = arr.size();
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= num) {
            high = mid;
        } else {
            low = mid+1 ; 
        }
    }
    return low;
}


int main() {
    // vector<int> array = {12, 34, 57, 78, 98};
    // vector<int> array = {1,2,2,3,3,5};
    vector<int>array={5,7,7,8,8,10};
    int num = 7;                
    int result = lowerbound(array, num);

    if (result != -1) {
        cout << "The lower bound is " <<result << endl;
    } else {
        cout << "No valid lower bound found." << endl;
    }

    return 0;
}
