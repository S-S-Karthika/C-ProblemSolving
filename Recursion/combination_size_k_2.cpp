




// combination of the array without repetation

#include<iostream>
#include<vector>
using namespace std;

void combination (int index,int size, vector<int>& arr, vector<vector<int>>&result, vector<int>&ans){
	
	if(ans.size()==size){
		result.push_back(ans);
		return;
	}
	for(int i=index;i<arr.size();i++){
		ans.push_back(arr[i]);
		combination(i+1,size,arr,result,ans);
		ans.pop_back();
	}
}



int main(){
	vector<int>arr={1,2,3,4};
	int size=2;
	vector<vector<int>>result;
	vector<int>currans;
	combination(0,size,arr,result,currans);
	for(const auto& subset : result){
	   cout<<" [ ";
	   for(int num : subset){
		cout<<num<<" ";
	   }
	   cout<<" ] ";
	}	
	return 0;
}