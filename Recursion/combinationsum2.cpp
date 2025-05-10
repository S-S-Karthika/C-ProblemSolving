
//sum without repetation -->combination


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void combinationsum2(int index,vector<int>&arr,vector<vector<int>>&result,vector<int>&ans,int target){

	if(target == 0){
		result.push_back(ans);
		return;
	}
	for(int i=index;i<arr.size();i++){
		if(arr[i]>target)break;
		if(i>index && arr[i]==arr[i-1])continue;   //for not allowing duplicates
		ans.push_back(arr[i]);
		combinationsum2(i+1,arr,result,ans,target-arr[i]);    //i+1 to not allow duplicates
		ans.pop_back();
	}

}



int main(){
	vector<int>arr={1,1,2,2,3};
	int target=3;
	vector<vector<int>>result;
	vector<int>ans;
	sort(arr.begin(),arr.end());
	combinationsum2(0,arr,result,ans,target);
	for(const auto& subset: result){
		cout<<" [ ";
		for(int num : subset){
			cout<<num <<" ";
		}
		cout<<" ] ";
	}
	return 0;
}