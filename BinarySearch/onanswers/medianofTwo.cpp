//Example 1:
//Input Format: n1 = 3, arr1[] = {2,4,6}, n2 = 3, arr2[] = {1,3,5}
//Result: 3.5
//Explanation: The array after merging 'a' and 'b' will be { 1, 2, 3, 4, 5, 6 }. As the length of the merged list is even, the //median is the average of the two middle elements. Here two medians are 3 and 4. So the median will be the average of 3 and 4, //which is 3.5.



#include<iostream>
#include<vector>
#include<climits>
using namespace std;


double median1 (vector<int>arr1,vector<int>arr2, int n1 ,int n2){
int i=0,j=0;
vector<int>ans;
while(i<n1 && j<n2){
  if(arr1[i]<arr2[j]){
     ans.push_back(arr1[i++]);
  }else{
     ans.push_back(arr2[j++]);
  }
}
  while(i<n1)ans.push_back(arr1[i++]);
  while(j<n2)ans.push_back(arr2[j++]);


int n=n1+n2;
if(n%2==1){
return ans[n/2];
}
return (ans[n/2 - 1]+ans[(n/2)])/2.0;

}

//------------------------------------------------------------------------------------------------------


double median2 (vector<int>arr1,vector<int>arr2, int n1 ,int n2){
int n=n1+n2;
int ele2=n/2;
int ele1=(n-1)/2;
int count =0,i=0,j=0;
int c1=-1 ,c2=-1;
while(i<n1 && j<n2){

if(arr1[i]<arr2[j]){
     if(count==ele1)c1=arr1[i];
     if(count==ele2)c2=arr1[i];
	count++;i++;
  }else{
     if(count==ele1)c1=arr2[j];
     if(count==ele2)c2=arr2[j];
	count++;j++;
  }
}
   while(i<n1){
	if(count==ele1)c1=arr1[i];
        if(count==ele2)c2=arr1[i];
	count++;i++;
   }
   while(j<n2){
	if(count==ele1)c1=arr2[j];
        if(count==ele2)c2=arr2[j];
	count++;j++;
   }
if(n%2==1){
return c2;
}
return (double)((double)(c1+c2))/2.0;

}


//------------------------------------------------------------------------------------------------

double median3 (vector<int>arr1,vector<int>arr2){
int n1 = arr1.size();
int n2= arr2.size();
if(n1>n2)return median3(arr2,arr1);
int low=0,high=n1;
int left=(n1+n2+1)/2;    //Contains the first left elements
int n =n1+n2;
while(low<high){
	int mid1=(low + high) / 2;
	int mid2=left-mid1;
	int l1=	INT_MIN,l2=INT_MIN;
	int r1=INT_MAX,r2=INT_MAX;
	if(mid1<n1)r1=arr1[mid1];
	if(mid2<n2)r2=arr2[mid2];
	if(mid1-1>=0)l1=arr1[mid1-1];
	if(mid2-1>=0)l2=arr2[mid2-1];
	if(l1<=r2 && l2<=r1){
		if(n%2 ==1)return max(l1,l2);
		return ((double)(max(l1,l2)+min(r1,r2)))/2.0;
	}
	else if(l1>r2)high=mid1-1;
	else low=mid1+1;
}
return 0;
}




int main(){

vector<int>arr1={2,4,6};
vector<int>arr2={1,3,5};
int n1=3,n2=3;
double ans=median1(arr1,arr2,n1,n2);
double ans1=median2(arr1,arr2,n1,n2);
double ans2 = median3(arr1,arr2);
cout<<ans<<endl;
cout<<ans1<<endl;
cout<<ans2;
return 0;

}