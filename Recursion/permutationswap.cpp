#include<iostream>
#include<vector>
using namespace std;


void permutationswap(int index,vector<int>&arr,vector<vector<int>>&res){

	if(index==arr.size()){
		vector<int>curr;
		for(int num : arr){
			curr.push_back(num);
		}
		res.push_back(curr);
		return;
	}
	for(int i=index;i<arr.size();i++){
		swap(arr[i],arr[index]);
		permutationswap(index+1,arr,res);
		swap(arr[i],arr[index]);
	}

}

int main(){
	vector<int>arr={1,2,3};
	vector<vector<int>>res;
	permutationswap(0,arr,res);
	for(auto& subset : res)
	{
		cout<<"[ ";
		for(int num:subset){
			cout<<num<<" ";
		}
		cout<<" ]";
	}
	return 0;

}