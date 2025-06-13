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

void method1(){
	vector<int>nums={1,2,3};
	vector<vector<int>>ans;
	int n=nums.size();
	for(int i=0;i<(1<<n);i++){
		vector<int>res;
		for(int j=0;j<n;j++){
			if(i&(1<<j))res.push_back(nums[j]);
		}
		ans.push_back(res);
	}
	
	for(auto & nums:ans){
		for(int num : nums)cout<<num<<" ";
		cout<<endl;
	}

}

int main(){
	vector<int>arr={1,2,3};
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
	cout<<endl;
	// Calling the method1 to demonstrate the bit manipulation approach
	method1();
	return 0;
}