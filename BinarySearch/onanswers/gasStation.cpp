//Example 1:
//Input Format: N = 5, arr[] = {1,2,3,4,5}, k = 4
//Result: 0.5
//Explanation: One of the possible ways to place 4 gas stations is {1,1.5,2,2.5,3,3.5,4,4.5,5}. Thus the maximum //difference between adjacent gas stations is 0.5. Hence, the value of ‘dist’ is 0.5. It can be shown that there is no //possible way to add 4 gas stations in such a way that the value of ‘dist’ is lower than this. 


#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int gasstation(vector<int>arr,int stations){
	
}

int main(){

	vector<int>arr={1,2,3,4,5};
	int k=4;
	int distance=gasstation(arr,k);
	cout<<distance;
	return 0;
}