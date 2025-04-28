//majority element n/2



#include<iostream>
#include<vector>
using namespace std;


int majority2(vector<int>arr){

	int cnt=1,num=arr[0];
	for(int i=1;i<arr.size();i++){
		if(cnt==0){
			cnt=1;
			num=arr[i];
		}else if(num == arr[i]){
			cnt++;
		}else{
			cnt--;
		}
	}
return num;

}



int main(){

	vector<int>arr={1,2,1,1,3,1,3,3,3,3,3};
	int num =majority2(arr);
	cout<<num;
	return 0;
}

