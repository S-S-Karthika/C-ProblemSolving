#include<iostream>
#include<vector>
#include<deque>
using namespace std;

vector<int> firstNegative(vector<int>arr,int k){
int n=arr.size();
deque<int>dq;
vector<int>res;

for(int i=0;i<n;i++){


if(arr[i]<0)dq.push_back(i);


if(!dq.empty() && dq.front()<i-k+1){
	dq.pop_front();
}

    if(i>=k-1){
      if(!dq.empty()){
	  res.push_back(arr[dq.front()]);
	}else{
	   res.push_back(0);
        }
    }
}

return res;

}






int main(){

vector<int>arr={12,-1,-7,8,15,30,16,28};
int k=3;
vector<int>ans= firstNegative(arr,k);
for(int i=0;i<ans.size();i++){

	cout<<ans[i]<<"\t\t";

}

return 0;

}