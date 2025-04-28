#include<iostream>
#include<vector>
using namespace std;

int upperbound(vector<char>arr,char target){
   int low=0,high=arr.size()-1;
   while(low<high){
	int mid = low+(high-low)/2;
	 if(arr[mid]>target){
		high=mid;
	}else{
		low=mid+1;
	}
   }
return high;
}



int main() {
    // vector<char>array={'a','b','c','f'};
    vector<char>array={'x','x','y','y'};
    char variable = 'x';                
    int result = upperbound(array, variable);

    if (result != -1) {
        cout << "The upper bound is " <<array[result] << endl;
    } else {
        cout << "No valid lower bound found." << endl;
    }

    return 0;
}