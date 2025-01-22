#include <iostream>
#include <vector>
using namespace std;

void merge(vector<pair<int, int>>& numWithIndex, vector<int>& counts, int low, int mid, int high) {
    vector<pair<int, int>> temp(high - low + 1);
    int left = low, right = mid + 1, k = 0;

    while (left <= mid && right <= high) {
        if (numWithIndex[left].first <= numWithIndex[right].first) {
            temp[k++] = numWithIndex[right++];
        } else {
            counts[numWithIndex[left].second] += (high - right + 1);
            temp[k++] = numWithIndex[left++];
        }
    }

    while (left <= mid) {
        temp[k++] = numWithIndex[left++];
    }

    while (right <= high) {
        temp[k++] = numWithIndex[right++];
    }

    for (int i = 0; i < temp.size(); i++) {
        numWithIndex[low + i] = temp[i];
    }
}

void mergeSort(vector<pair<int, int>>& numWithIndex, vector<int>& counts, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(numWithIndex, counts, low, mid);
        mergeSort(numWithIndex, counts, mid + 1, high);
        merge(numWithIndex, counts, low, mid, high);
    }
}

vector<int> countSmaller(vector<int>& array) {
    int n = array.size();
    vector<pair<int, int>> numWithIndex(n);
    vector<int> counts(n, 0);

    for (int i = 0; i < n; i++) {
        numWithIndex[i] = {array[i], i};
    }

    mergeSort(numWithIndex, counts, 0, n - 1);
    return counts;
}

int main() {
     vector<int>arr={7,4,0,6,2,7};
    // vector<int>arr={1,2,3,4,5,6};
    // vector<int>arr={863,9086,5372673,0000,456};
    // vector<int> arr = {5, 2, 6, 1};
    vector<int> ans = countSmaller(arr);
    for (int count : ans) {
        cout << count << " ";
    }
    return 0;
}
