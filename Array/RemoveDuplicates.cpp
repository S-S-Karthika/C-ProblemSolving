#include <iostream>
#include <vector>
using namespace std;

int uniqueElement(vector<int> nums) {
    int count = 1; // Start with the first element being unique
    int prev = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != prev) {
            count++;
            prev = nums[i]; // Update prev to the new unique element
        }
    }
    return count;
}

int main() {
    vector<int> nums = {1, 1, 2, 2, 2, 2, 2,3,4,5,5,9};
    int unique = uniqueElement(nums);
    cout << "The number of unique elements is " << unique << endl;
    return 0;
}
