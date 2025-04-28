#include <iostream>
#include<math.h>
using namespace std;


bool checkArmstrong(int n){
	int original =n;
	int k = to_string(n).length();
	int ans=0;
	while(n>0){
		int power =1;
		int digit = n%10;
		for(int i=0;i<k;i++){
			power*=digit;
		}
		n/=10;
		ans+=power;
	}
	return (original == ans);
}

int main(){
    int n=150;
    bool output = checkArmstrong(n);
    cout<<"The Amstrong number is "<<output<<endl;
}