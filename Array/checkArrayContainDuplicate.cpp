#include <iostream>
#include <vector>
#include<unordered_set>
#include<algorithm>//for sort()
using namespace std;

bool checkArrayContainDuplicate (vector<int>&arr){
    sort(arr.begin(),arr.end());
    for(int i =1;i<arr.size();i++){
        if(arr[i]==arr[i-1]){
            return true;
        }
    }
    return false;
}


class Solution{

public:
   bool containDuplicate(vector<int>&arr){
        unordered_set<int>seen;
        for(int num : arr){
            if(seen.find(num) != seen.end()){
               return true;
            }
             seen.insert(num);
        }
        return false;
   }
};



int main(){
    Solution solution;
    vector<int>arr={1,2,3,4};
    //  vector<int>arr={1,2,3,4,4};
    //   vector<int>arr={1,1,2,3,4};
    cout<<"The array is "<<(checkArrayContainDuplicate(arr)? "not unique" : "unique") <<endl;
    cout << "Using containsDuplicate: The array is "<< (solution.containDuplicate(arr) ? "not unique" : "unique") << endl;
    return 0;
}