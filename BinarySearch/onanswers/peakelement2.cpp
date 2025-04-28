

#include<iostream>
#include<vector>
using namespace std;


int maxelement(vector<vector<int>>& arr,int col){
    int row=arr.size();
    int maxind=0;
    int maxi=arr[0][col];
    for(int i=1;i<row;i++){
        if(arr[i][col]>maxi){
            maxi=arr[i][col];
            maxind=i;
        }
    }
return maxind;
}

vector<int> findPeakGrid(vector<vector<int>>& arr) {
        int cols=arr[0].size();
        int low=0,high = arr[0].size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int row=maxelement(arr,mid);
            int left=(mid-1>0)?arr[row][mid-1]:-1;
            int right=(mid+1<cols)?arr[row][mid+1]:-1;
            if(   arr[row][mid] >left && arr[row][mid]>right){
                return{row,mid};
            }else if(arr[row][mid]<right){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return {-1,-1};
    }


int main(){

	vector<vector<int>>arr={{1,4},{2,3}};
	vector<int>res = findPeakGrid(arr);
	cout<<res[0]<<" "<<res[1];
	return 0;


}






