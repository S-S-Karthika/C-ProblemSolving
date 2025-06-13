
// Your code is solving the "Staircase Problem" (a variation of the climbing stairs problem) where:

// From step 0, you can jump 1, 2, or 3 steps at a time.
// Find the total number of ways to reach step n.


#include<iostream>
using namespace std;

int jump(int n){

if(n==0)return 1;
if(n<0)return 0;
return jump(n-1)+jump(n-2)+jump(n-3);

}


int main(){

	int n=4;
	int count=jump(n);
	
	cout<<count;

}