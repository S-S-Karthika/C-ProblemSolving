#include<iostream>
using namespace std;

int binary(int n) {
    const int MOD = 1e9 + 7;
    int zeroend = 1;
    int oneend = 1;

    if (n == 1) return (zeroend + oneend) % MOD;

    int sum = 0;

    for (int i = 2; i <= n; i++) {
        int newOneEnd = zeroend;
        int newZeroEnd = (zeroend + oneend) % MOD;
        oneend = newOneEnd;
        zeroend = newZeroEnd;
        sum = (oneend + zeroend) % MOD;
    }

    return sum;
}

int recursive(int n,int last){
	
	if(n==0)return 1;
	if(last==1){
		return recursive(n-1,0);
	}else{
		return (recursive(n-1,0)+recursive(n-1,1));
	}

}

int solve(int n){
	return (recursive(n-1,0)+recursive(n-1,1));
}



int main() {
    int ans = binary(30);
    int ans1=solve(30);
    cout << ans<<endl;  
    cout<<ans1;
    return 0;
}
