#include<iostream>
using namespace std;
#include<vector>

vector<vector<int>>printsubset(vector<int>arr){
  int size = arr.size();
  vector<vector<int>>result;
  for(int i=0;i<(1<<size);i++){
    vector<int>subnets;
    for(int j=0;j<size;j++){
      if(i&(1<<j)){
        subnets.push_back(arr[j]);
      }
    }
    result.push_back(subnets);
  }
  return result;
}


int main(){
  vector<int>arr={1,2,3};
  vector<vector<int>>ans= printsubset(arr);
   for (const auto& subset : ans) { // Iterate over each subset
        cout << "[";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    // vector<vector<int>>ans= recusionsubset(arr);

  return 0;

}