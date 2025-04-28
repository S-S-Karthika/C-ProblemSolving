#include <iostream>
#include <vector>
using namespace std;

int brute(const vector<int>& arr, int n) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] > 2 * arr[j]) count++;
        }
    }
    return count;
}

int reversepair(vector<int>& arr, int low, int mid, int high) {
    int cnt = 0;
    int right = mid + 1;
    for (int i = low; i <= mid; i++) {
        while (right <= high && arr[i] > 2LL * arr[right]) {
            right++;
        }
        cnt += (right - (mid + 1));
    }
    return cnt;
}

void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low, right = mid + 1;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left++]);
        } else {
            temp.push_back(arr[right++]);
        }
    }

    while (left <= mid) temp.push_back(arr[left++]);
    while (right <= high) temp.push_back(arr[right++]);

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

int mergesort(vector<int>& arr, int low, int high) {
    if (low >= high) return 0;
    int mid = (low + high) / 2;
    int cnt = 0;
    cnt += mergesort(arr, low, mid);
    cnt += mergesort(arr, mid + 1, high);
    cnt += reversepair(arr, low, mid, high);
    merge(arr, low, mid, high);
    return cnt;
}

int main() {
    vector<int> original = {1, 3, 2, 3, 1};
    vector<int> copy = original;

    int optimizedCount = mergesort(copy, 0, copy.size() - 1);
    int bruteCount = brute(original, original.size());

    cout << optimizedCount << endl;  // Should print 2
    cout << bruteCount << endl;      // Should print 2
    return 0;
}
