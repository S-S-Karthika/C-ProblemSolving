#include <iostream>
#include <vector>
using namespace std;

int lowerbound(vector<char>& arr, char variable) {
    int low = 0, high = arr.size();
    if(variable>arr[high-1]){
        return low;
    }
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= variable) {
            low = mid+1 ;  
        } else {
            high = mid;
        }
    }
    return low;
}


int main() {
    // vector<char>array={'a','b','c','f'};
    vector<char>array={'x','x','y','y'};
    char variable = 'z';                
    int result = lowerbound(array, variable);

    if (result != -1) {
        cout << "The lower bound is " <<array[result] << endl;
    } else {
        cout << "No valid lower bound found." << endl;
    }

    return 0;
}
