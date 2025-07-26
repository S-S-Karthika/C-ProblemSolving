#include<bits/stdc++.h>
using namespace std;

int main(){

vector<vector<int>>arr={{1,2,3},{4,5,6},{7,8,9}};
int n=arr.size();
int m=arr[0].size();
int rowstart=0,rowend=n-1,colend=n-1,colstart=0;
	while(rowstart<=rowend && colstart<=colend){
		for(int j=colstart;j<=colend;j++){
			cout<<arr[rowstart][j]<<" ";
		}
		rowstart++;
		for(int j=rowstart;j<=rowend;j++){
			cout<<arr[j][colend]<<" ";
		}
		colend--;
		if(rowstart<=rowend){
		for(int j=colend;j>=colstart;j--){
			cout<<arr[rowend][j]<<" ";
		}
		rowend--;
		}
		if(colstart<=colend){
		 for(int j=rowend;j>=rowstart;j--){
			cout<<arr[j][colstart]<<" ";
		}
		colstart++;
		}
	}

}