//Example 1:
//Input Format: N = 6, array[] = {9, -3, 3, -1, 6, -5}
//Result: 5
//Explanation: The following subarrays sum to zero:
//{-3, 3} , {-1, 6, -5}, {-3, 3, -1, 6, -5}
//Since we require the length of the longest subarray, our answer is 5!


#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


int largestsum(vector<int>arr){
	int n=arr.size(),sum=0,maxlen=0;
	unordered_map<int,int>mpp;
	for(int i=0;i<n;i++){
		sum+=arr[i];
		if(sum==0){
			maxlen=i+1;
		}else{
			if(mpp.find(sum)!=mpp.end()){
				maxlen=max(maxlen,i-mpp[sum]);
			}else{
				mpp[sum]=i;
			}
	   	}
	}

return maxlen;
}



int main(){

vector<int>array={9, -3, 3, -1, 6, -5};
int total = largestsum(array);
cout<<total;
return 0;

}