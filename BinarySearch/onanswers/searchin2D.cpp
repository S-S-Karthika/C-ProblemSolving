//Example 1:
//Input Format: N = 3, M = 4, target = 8,
//mat[] = 
//1 2 3 4
//5 6 7 8 
//9 10 11 12
//Result: true
//Explanation: The ‘target’  = 8 exists in the 'mat' at index (1, 3).


#include<iostream>
#include<vector>
using namespace std;


int targetmatch(vector<vector<int>>arr,int row,int col,int target){

int low=0,high=row-1,ans=row;

while(low<=high){
int mid =low+(high-low)/2;

if(arr[mid][0]==target){
	return mid;
}else if(arr[mid][0]<target){
	ans=mid;
	low=mid+1;
}else{
high=mid-1;
}

}
return ans;

}

bool targetfound(vector<vector<int>>arr,int row,int col,int target){

int index=targetmatch(arr,row,col,target);
int low=0,high=col-1;
while(low<=high){
int mid=low+(high-low)/2;
if(arr[index][mid]==target){
	return true;
}else if(arr[index][mid]<target){
	low=mid+1;
}else{
	high=mid-1;
}

}
return false;
}




int main(){

vector<vector<int>>arr={{1 ,2, 3, 4},{5 ,6 ,7 ,8},{9 ,10 ,11 ,12}};
int target=27;
int row= arr.size(),col =arr[0].size();
bool found = targetfound(arr,row,col,target);
if(found)cout<<"True";
else cout<<"False";
return 0;

}