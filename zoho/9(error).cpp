// Find the least prime number that can be added with first array element that makes them
//divisible by second array elements at respective index

#include<bits/stdc++.h>
using namespace std;

bool isprime(int num){
	if(num<=1)return false;
	for(int i=2;i*i<=num;i++){
		if(num%i ==0)return false;
	}
return true;
}

int func(vector<int>arr1,vector<int>arr2){

int base=arr1[0];
int p=2;
while(true){
	if(isprime(p)){
		bool isvalid=true;
		for(int num: arr2){
			if((base+p)%num !=0){
			  isvalid=false;
			  break;
			}
		}
	   if(isvalid)return p;
	}
p++;
	
}


}

int main(){

vector<int>arr1={10};
vector<int>arr2={2,4,6};

int num=func(arr1,arr2);
cout<<num;

}
