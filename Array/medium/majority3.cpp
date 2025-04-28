//majority 3

#include<iostream>
#include<vector>
using namespace std;

vector<int>majority (vector<int>arr){
	int cnt1=0,cnt2=0;
	int n=arr.size();
	int num1=-1,num2=-1;
	for(int i=0;i<n;i++){
		 if(arr[i] == num1){
			cnt1++;
		}else if(arr[i]==num2){
			cnt2++;
		}else if(cnt1==0 ){
			num1=arr[i];
			cnt1=1;
		}else if(cnt2 == 0 ) {
			num2=arr[i];
			cnt2=1;
		}
		else{
			cnt1--;
			cnt2--;
		}
	}
	cnt1=0,cnt2=0;
	vector<int>res;
	int occurance = n/2;
        for(int i=0;i<n;i++){
		if(arr[i]==num1){
			cnt1++;
		}
		if(arr[i]==num2){
			cnt2++;
		}
	} 
	if(cnt1>=occurance){
		res.push_back(num1);
	}else{
		res.push_back(-1);
	}
	if(cnt2>=occurance){
		res.push_back(num2);
	}else{
		res.push_back(-1);
	}
return res;
}


int main(){

	vector<int>arr={11,33,33,11,33,11};
	vector<int>res=majority(arr);
	cout<<res[0]<<" ";
	cout<<res[1];
	return 0;

}