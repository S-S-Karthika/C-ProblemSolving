#include<iostream>
#include<vector>
using namespace std;

double findmaxAvgsubarray(vector<int>nums , int k){
	double sum=0,maxi=0;
	int n=nums.size();
	for(int i=0;i<k;i++){
		sum+=nums[i];
	}
	maxi=sum;
	for(int i=k;i<n;i++){
		sum+=nums[i];
		sum-=nums[i-k];
		maxi= max(sum,maxi);
	}
	return maxi/k;
}


int main(){
	//vector <int>nums={1,12,-5,-6,50,3};
	//int k=4;
	vector<int>nums={5};
	int k=1;
	double ans = findmaxAvgsubarray(nums,k);
	cout<<"The Maximum Average Sum is "<<ans;
	return 0;
}