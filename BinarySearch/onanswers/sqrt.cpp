//Problem Statement: You are given a positive integer n. Your task is to find and return its square root. If ‘n’ is //not a perfect square, then return the floor value of 'sqrt(n)'.


#include <bits/stdc++.h>
using namespace std;

long long brute(int n){
	long long ans = 0;
	for(int i = 0; i * i <= n; i++){
		ans = i;
	}
	return ans;
}


int power(int n){
	long long ans= sqrt(n);
	return ans;
}

long long optimal1(int n){

	long long ans=power(n);
	return ans;

}

long long optimal2(int n){

	int low=0;
	int high=n;
	long long ans=0;
	while(low<high){
		long long  mid =low+(high-low)/2;
		
		long long val=mid*mid;
		if(val<=(long long)(n)){
		    ans =low;
		    low=mid+1;
		   
		}else{
		   high = mid-1;
		}
	}
	return ans;

}


int main(){

	int n=36;
	long long ans1 = brute(n); 
	long long ans2 = optimal1(n); 
	long long ans3 = optimal2(n); 
	cout<<ans1<<"  "<<ans2<<"  "<<ans3;
	return 0;

}