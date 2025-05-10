

//just print one subset whose sum is equal to target

#include<iostream>
#include<vector>
using namespace std;

bool printsubsetsum (int index,int target, vector<int>& arr, vector<int>&ans){
	
	
	if(index == arr.size() )
	{	
		if(target==0){
			return true;		
		}
		return false;
	}

	ans.push_back(arr[index]);
	if(printsubsetsum(index+1,target-arr[index],arr,ans))return true;
	ans.pop_back();
	if(printsubsetsum(index+1,target,arr,ans))return true;
	
}



int main(){
	vector<int>arr={1,2,3,4,5};
	int target=7;
	vector<int>currans;
	printsubsetsum(0,target,arr,currans);
	   cout<<"[";
	   for(int num : currans){
		cout<<num<<" ";
	   }
	 cout<<" ]"<<endl;	


     return 0;
}