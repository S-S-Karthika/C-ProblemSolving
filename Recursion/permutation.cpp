#include<iostream>
#include<vector>
using namespace std;


void permutation(int index,vector<int>&arr,vector<vector<int>>&res,vector<int>&curr,vector<int>&freq ){

	if(curr.size()==arr.size()){
		res.push_back(curr);
		return;
	}
	for(int i=index;i<arr.size();i++){
		if(!freq[i]){
			curr.push_back(arr[i]);
			freq[i]=true;
			permutation(index,arr,res,curr,freq);
			curr.pop_back();
			freq[i]=false;
		}
	}

}

int main(){

	vector<int>arr={1,2,3};
	vector<vector<int>>res;
	vector<int>curr;
	vector<int>freq(arr.size(),0);
	permutation(0,arr,res,curr,freq);
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