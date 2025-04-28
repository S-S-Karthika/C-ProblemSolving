// Example:
// Input: ‘n’ = 336

// Output: 3

// Explanation:
// 336 is divisible by both ‘3’ and ‘6’. Since ‘3’ occurs twice it is counted two times.
















#include<bits/stdc++.h>
using namespace std;


int countDigits(int n){
	int original = n;
	int count=0;
	while(n>0){
		int digit=n%10;
		n=n/10;
		if (digit == 0) {
            continue;
        }
		if(original%digit ==0 && digit!=0 ){
            count++;
		}
		
	}
	return count;
}


int main(){
    int n=1012;
    int output = countDigits(n);
    cout<<"The count is "<<output<<endl;
    return 0;
}