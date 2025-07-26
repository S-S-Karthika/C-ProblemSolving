//Find Element Appears Once  single element-1(nonconsecutive).
#include <bits/stdc++.h>
using namespace std;

int main(){
vector<int>arr={1,0,1,0,5,8,5};
int ans=0;
for(int i=0;i<arr.size();i++){
	ans^=arr[i];
}
cout<<ans<<endl;

vector<int>arr1={5,5,1,1,3,9,9};
int low=0,high=arr1.size()-1;
while(low<high){
	int mid=low+(high-low)/2;
	if(mid%2 ==1)mid--;
	if(arr1[mid]==arr1[mid+1]){
		low=mid+2;
	}else{
		high=mid;
	}
}
cout<<arr1[high];

}
