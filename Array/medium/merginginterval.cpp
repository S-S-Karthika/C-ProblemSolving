// Input: intervals=[[1,3],[2,6],[8,10],[15,18]]

// Output: [[1,6],[8,10],[15,18]]

// Explanation: Since intervals [1,3] and [2,6] are overlapping we can merge them to form [1,6]
// intervals.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<vector<int>>overlap(vector<vector<int>>arr){
int n=arr.size();
sort(arr.begin(),arr.end());
vector<vector<int>>ans;
ans.push_back(arr[0]);
for(int i=1;i<n;i++){
vector<int>& val = ans.back();
if(arr[i][0]<val[1]){
val[1]=max(val[1],arr[i][1]);

}else{
ans.push_back(arr[i]);
}

}

return ans;
}

int main(){

vector<vector<int>>arr={{1, 3}, {8, 10}, {2, 6}, {15, 18}};
vector<vector<int>>ans=overlap(arr);
	for(auto subset : ans){
		for(int num : subset ){
			cout<<num<<" ";
		}
		cout<<endl;
	}
return 0;
}