//Input: 
//n = 4, arr1[] = [1 4 8 10] 
//m = 5, arr2[] = [2 3 9]

//Output: 
//arr1[] = [1 2 3 4]
//arr2[] = [8 9 10]

//Explanation:
//After merging the two non-decreasing arrays, we get, 1,2,3,4,8,9,10.


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void merging(vector<int>&arr1,vector<int>&arr2){


int n1=arr1.size(),n2=arr2.size();
int left =n1-1,right=0;

while(left>=0 && right<n2){

if(arr1[left]>arr2[right]){
	swap(arr1[left],arr2[right]);
	left--,right++;
}else{
	break;
}

}
sort(arr1.begin(),arr1.end());

sort(arr2.begin(),arr2.end());
}



int main(){

vector<int>arr1={1,4,8,10};
vector<int>arr2={2,3,9};
int n = 4, m = 3;
merging(arr1,arr2);

cout << "arr1[] = ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;return 0;
}