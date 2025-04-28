//Input:
// Nums = [1,2,-3,0,-4,-5]
//Output:
// 20
//Explanation:
// In the given array, we can see (-4)×(-5) gives maximum product value.


#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std;

int maxproduct(vector<int>arr){

int maxval=INT_MIN,minval=INT_MAX;
int currval=1;

for(int num :arr){

	if(num<0){
		swap(minval,maxval);
	}
	
	maxval=max(num,maxval*num);
	minval=min(num,minval*num);
}

return maxval;

}


int better(vector<int>arr){
	int maxi=arr[0],n=arr.size();
	for(int i=0;i<n;i++){
		int prod=1;
		for(int j=i;j<n;j++){
			prod*=arr[j];
			maxi=max(maxi,prod);
		}
	}
return maxi;
}



int main(){

vector<int>arr={1,2,-3,0,-4,-5};
int ans1 =better(arr);
int ans = maxproduct(arr);
cout<<ans;
cout<<endl;
cout<<ans1;
return 0;

}