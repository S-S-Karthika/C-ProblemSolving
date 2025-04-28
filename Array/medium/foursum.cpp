// four sum 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<vector<int>> foursum (vector<int>arr,int target){

	sort(arr.begin(),arr.end());
	vector<vector<int>>ans;
	int n = arr.size();
	long long sum = 0;

	for(int i=0;i<n-3;i++){
		if(i>0 && arr[i]==arr[i-1])continue;
		for(int j=i+1;j<n-2;j++){
			if(j>i+1  && arr[j]==arr[j-1])continue;
			int low=j+1,high=n-1;
			while(low<high){
				long long sum = (long long)arr[i] + arr[j] + arr[low] + arr[high];

				if(sum<target){
					low++;
				}else if (sum>target){
					high--;
				}else{
					vector<int>temp = {arr[i], arr[j], arr[low], arr[high]};
					ans.push_back(temp);
					low++,high--;
					while(low<high && arr[low]==arr[low-1])low++;
					while(low<high && arr[high]==arr[high+1])high--;
				}
			}
		}
	}
return ans;

}




int main(){

vector<int>arr={1, 0, -1, 0, -2, 2};
int target = 0;

vector<vector<int>>ans=foursum(arr,target);
for(auto subset : ans) {
        for(int num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }
return 0;
}