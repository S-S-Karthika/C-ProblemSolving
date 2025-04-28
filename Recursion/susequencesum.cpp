#include<iostream>
#include<vector>
using namespace std;

void printsubsetsum (int index,int target, vector<int>& arr, vector<vector<int>>&result, vector<int>&ans){
	
	if(target==0){
		result.push_back(ans);
		return;		
	}
	if(index == arr.size() || target<0)
	{	
		return;
	}

	ans.push_back(arr[index]);
	printsubsetsum(index+1,target-arr[index],arr,result,ans);
	ans.pop_back();
	printsubsetsum(index+1,target,arr,result,ans);
	
}



int main(){
	vector<int>arr={1,2,3,4,5};
	int target=6;
	vector<vector<int>>result;
	vector<int>currans;
	printsubsetsum(0,target,arr,result,currans);
	for(const auto& subset : result){
	   cout<<" [ ";
	   for(int num : subset){
		cout<<num<<" ";
	   }
	   cout<<" ] ";
	}	
	return 0;
}