#include<iostream>
#include<string>
#include<vector>
using namespace std;

//n is the number of digits and k is the which permutation

string getPermutation(int n, int k) {
    vector<int> nums;
    int fact = 1;
    for (int i = 1; i <= n; ++i) {
        nums.push_back(i);
        fact *= i;
    }
	if(fact<k)return "Invalid input: k exceeds total permutations";
    k -= 1; // Convert to 0-based index
    string result;

    for (int i = 0; i < n; ++i) {
        fact /= (n - i); // (n-1)!
        int index = k / fact;
        result += to_string(nums[index]);
        nums.erase(nums.begin() + index);
        k %= fact;
    }

    return result;
}


int main(){
	int k =17;
	int n=4;
	string s = getpermutation(n,k);
	cout << "Final permutation: " << s << endl;
	return 0;
}