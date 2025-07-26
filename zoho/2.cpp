//Given an array of numbers. Print the numbers without duplication.

#include<iostream>
#include<vector>
#include<set>
using namespace std;


int main(){
vector<int>arr={1,2,3,5,6,1,2,3,7};
int n=arr.size();
set<int>st;
for(int i=0;i<n;i++){
	st.insert(arr[i]);
}
for(int num:st)cout<<num;


}
