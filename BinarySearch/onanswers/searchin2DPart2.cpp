//Example 1:
//Input Format: N = 5, M = 5, target = 14
//mat[] = 

//Result: true
//Explanation: Target 14 is present in the cell (3, 2)(0-based indexing) of //the matrix. So, the answer is true.



#include<iostream>
#include<vector>
using namespace std;

bool found(vector<vector<int>>arr,int target,int row,int col){
int low=0, high=col-1;

while(low<row && high>=0){
if(arr[low][high]==target){
return true;
}else if(arr[low][high]<target){
 high--;
}else{
low++;
}

}
return false;

}


int main(){

vector<vector<int>>arr={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
int row=arr.size();
int col =arr[0].size();
int target =150;
if(found(arr,target,row,col))cout<<"The element is found";
else cout<<"The element is not found";


}