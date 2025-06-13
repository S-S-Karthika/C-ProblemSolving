//Example 1:
//Input Format: N = 5, arr[] = {1,2,3,4,5}, k = 4
//Result: 0.5
//Explanation: One of the possible ways to place 4 gas stations is {1,1.5,2,2.5,3,3.5,4,4.5,5}. Thus the maximum //difference between adjacent gas stations is 0.5. Hence, the value of ‘dist’ is 0.5. It can be shown that there is no //possible way to add 4 gas stations in such a way that the value of ‘dist’ is lower than this. 


#include<bits/stdc++.h>
using namespace std;


long double gas(vector<int>arr,int k, int n){
	priority_queue<pair<long double,int>> pq;
	vector<int>howmany(n-1,0);
	for(int i=0;i<n-1;i++){
		pq.push({arr[i+1]-arr[i],i});
	}
	for(int station=1;station<=k;station++){
		auto tp=pq.top();
		pq.pop();
		int index=tp.second;
		howmany[index]++;
		long double difference=arr[index+1]-arr[index];
		long double newlen= difference /(long double)(howmany[index]+1);
		pq.push({newlen,index});
	}
return pq.top().first;
}




int main(){
	vector<int>arr={1,2,3,4,5};
	int k=4;
	long double ans=gas(arr,k,arr.size());
	cout<<ans;
}