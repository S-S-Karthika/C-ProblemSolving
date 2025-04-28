#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int kthelement (vector<int>arr1,vector<int>arr2, int n1 ,int n2,int k){

int count =0,i=0,j=0;
int c1=-1;
while(i<n1 && j<n2){

	if(arr1[i]<arr2[j]){
	        if(count==k-1)c1=arr1[i];
		count++;i++;
  	}else{
     		if(count==k-1)c1=arr2[j];
		count++;j++;
  	}
}

while(i<n1){
	if(count==k-1)c1=arr1[i];
	count++;i++;
}
while(j<n2){
	if(count==k-1)c1=arr2[j];
	count++;j++;
}
return c1;

}





int main(){

vector<int>arr1={2,4,6};
vector<int>arr2={1,3,5};
int n1=3,n2=3;
int k=4;

int ans1=kthelement(arr1,arr2,n1,n2,k);

cout<<ans1<<endl;

return 0;

}