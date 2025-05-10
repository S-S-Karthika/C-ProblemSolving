// it is exact of the subsequence problem it not worry about the duplicates and the order


#include<iostream>
#include<vector>
using namespace std;

void printsubset (int index, vector<int>& arr, vector<vector<int>>&result, vector<int>&ans){
	if(index == arr.size()){
		result.push_back(ans);
		return;
	}
	
	printsubset(index+1,arr,result,ans);
	ans.push_back(arr[index]);
	printsubset(index+1,arr,result,ans);
	ans.pop_back();
}



int main(){
	vector<int>arr={1,1,2,2,3};
	vector<vector<int>>result;
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