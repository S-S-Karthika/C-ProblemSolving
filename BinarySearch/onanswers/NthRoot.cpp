#include<iostream>
using namespace std;

long long func(int i, int expo){
	long long ans=1;
	long long base=i;
	while(expo>0){
		if(expo%2){
			expo--;
			ans=ans*base;
		}else{
			expo/=2;
			base=base*base;
		}
	}
return ans;

}

int brute(int n, int m){

	for(int i=1;i<=m;i++){
		long long val = func(i,n);
		if(val== (long long)(m))return i;
		else if(val>(long long)(m))break;
	}
	return -1;
}


int func(int mid, int n,int m){
	long long ans=1;
	for(int i=1;i<=n;i++){
	   ans=ans*mid;
	   if(ans>m)return 2;
	}
	if(ans == m)return 1;
	return 0;

}


int optimal(int n,int m){
	int low=0;
	int high=m;
	while(low<=high){
		int mid =low+(high-low)/2;
		int ans =func(mid,n,m);
		if(ans== 1)return mid ;
		else if(ans==2)high=mid-1;
		else low=mid+1;
	}
	return -1;
}

int main(){

int n=4;
int m=625;
int ans1=brute(n,m);
int ans2=optimal(n,m);
cout<<ans1<<"  "<<ans2;
return 0;
}