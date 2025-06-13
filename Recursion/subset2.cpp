//using set so removes duplicates


#include<iostream>
#include<vector>
#include<set>
using namespace std;

void printsubset (int index, vector<int>& arr, set<vector<int>>&result, vector<int>&ans){
	if(index == arr.size()){
		result.insert(ans);
		return;
	}
	
	printsubset(index+1,arr,result,ans);
	ans.push_back(arr[index]);
	printsubset(index+1,arr,result,ans);
	ans.pop_back();
}

//but arr should be sorted to avoid duplicates in the result
void printsubset(int index, vector<int>& arr, vector<vector<int>>& result, vector<int>& ans) {
    result.push_back(ans);

    for(int i = index; i < arr.size(); i++) {
        // Skip duplicates at the same level
        if(i > index && arr[i] == arr[i - 1]) continue;

        ans.push_back(arr[i]);
        printsubset(i + 1, arr, result, ans);
        ans.pop_back();
    }
}


int main(){
	vector<int>arr={1,1,2,2,3};
	set<vector<int>>result;
	vector<int>currans;
	printsubset(0,arr,result,currans);
	for(const auto& subset : result){
	   cout<<" [ ";
	   for(int num : subset){
		cout<<num<<" ";
	   }
	   cout<<" ] ";
	}	
	return 0;
}