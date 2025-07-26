// Prime number – print n prime numbers

#include<bits/stdc++.h>
using namespace std;



int main(){

int num=30;
vector<bool>occur(num,true);
occur[0]=false;
occur[1]=false;

for(int i=2;i<=sqrt(num);i++){
	if(occur[i]){
		for(int j=i*i;j<=num;j+=i){
			occur[j]=false;
		}
	}
}
for(int i=0;i<occur.size();i++){
if(occur[i])cout<<i<<" ";
}
}
