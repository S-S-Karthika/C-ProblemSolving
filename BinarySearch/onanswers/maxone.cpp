//Example 1:
//Input Format: n = 3, m = 3, 
//mat[] = 
//1 1 1
//0 0 1
//0 0 0
//Result: 0
//Explanation: The row with the maximum number of ones is 0 (0 - indexed).



#include<iostream>
#include<vector>
using namespace std;

int maxone(vector<vector<int>>arr,int row,int col){

int index=-1,maxcnt=0;
for(int r=0;r<row;r++){
	int count=0;
	for(int c=0;c<col;c++){
		if(arr[r][c]==1)count++;
	}
	if(count>maxcnt){
		maxcnt=count;
		index=r;
	}
}

return index;

}
//--------------------------------------------------------------------------


int firstoccurance(vector<int>arr,int row,int col){

int low=0,high=col,first=col;//if there is no one default send the col
while(low<=high){
int mid=low+(high-low)/2;
if(arr[mid]==0){
low=mid+1;
}else{
first = mid;
high=mid-1;
}
}
return first;
}





int maxone1(vector<vector<int>>arr,int row,int col){

int index=-1,maxcnt=0;
for(int r=0;r<row;r++){

int maxones=col-firstoccurance(arr[r],row,col);
if(maxones>maxcnt){
maxcnt=maxones;
index=r;
}

}

return index;

}








int main(){
vector<vector<int>>arr={{0,0,0},{0,0,0},{0,0,0}};
int row=arr.size(), col =arr[0].size();
int count = maxone(arr,row,col);
cout<<"The max one is "<<count<<endl;
int count1 = maxone1(arr,row,col);
cout<<"The max one is "<<count1;

return 0;

}