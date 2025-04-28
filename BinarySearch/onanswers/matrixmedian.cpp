//Example 1:
//Input Format:M = 3, N = 3,
//matrix[][] =
//   1 4 9 
//   2 5 6
//   3 8 7
//Result: 5
                    
//Explanation:  If we find the linear sorted array, the array becomes 1 2 3 4 5 6 7 8 9. So, //median = 5


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int upperbound(vector<int>arr,int target){

int low=0;
int high =arr.size();
while(low<high){
int mid =low+(high-low)/2;
if(arr[mid]<=target){
low=mid+1;
}else{
high=mid;
}
}
return low;
}


int blackbox(vector<vector<int>>arr,int mid){
int n=arr.size();
int sum=0;
for(int i=0;i<n;i++){
sum+=upperbound(arr[i],mid);
}
return sum;
}


int median(vector<vector<int>>arr){

int row=arr.size();
int col = arr[0].size();
int req=(row*col)/2;
int low=*min_element(arr[0].begin(),arr[0].end());
int high=*max_element(arr[row-1].begin(),arr[row-1].end());

while(low<=high){
	int mid =low+(high-low)/2;
	int smaller=blackbox(arr,mid);
	if(smaller<=req)low=mid+1;
	else high=mid-1;
}
return low;

}




int main(){
vector<vector<int>>matrix={{1,4,9},{2,5,6},{3,8,7}};
int res=median(matrix);
cout<<res;
return 0;
}