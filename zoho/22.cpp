//count-possible-triangles

#include <bits/stdc++.h>
using namespace std;




int main(){

vector<int>arr={4,6,3,7};
int n=arr.size();
int count=0;
sort(arr.begin(),arr.end());
for(int i=n-1;i>=2;i--){
	int k=0,j=i-1;
	while(k<j){
		if(arr[k]+arr[j]>arr[i]){
			count+=(j-k);
			j--;
		}
		else k++;
	}
}
cout<<count;
}


