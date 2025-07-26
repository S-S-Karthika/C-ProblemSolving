//Move Zeroes to End of Array
#include <bits/stdc++.h>
using namespace std;

int main(){
vector<int>arr={1,0,8,0,7,0,5};
int j=0;
for(int i=0;i<arr.size();i++){
	if(arr[i]!=0)arr[j++]=arr[i];
}
while(j<arr.size()){
arr[j++]=0;
}
for(int i=0;i<arr.size();i++)cout<<arr[i]<<" ";
return 0;
}
