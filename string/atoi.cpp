#include<iostream>
#include<string>
#include<cctype>
#include<climits>
using namespace std;


int partialcorrect(const string &s){
	int i=0,n=s.size(),sign=1;
	while(i<n){
		if(s[i]==' '){
			i++;
		}else{
			break;
		}	
	}
	if(i<n && s[i]=='-'){
		sign=-1;
		i++;
	}
	
	string ans="";
	while(i<n && isdigit(s[i])){
		ans+=s[i];
		i++;
	}
	if(ans.empty())return 0;
	long long result = 0; // Use long long to handle overflow
        for (char c : ans) {
            result = result * 10 + (c - '0');
            if (result * sign > INT_MAX) return INT_MAX;   // Overflow
            if (result * sign < INT_MIN) return INT_MIN;   // Underflow
        }
	return long*sign;
}
int myAtoi(string s) {
        int ans=0;
        int sign=1;
        int i=0,n=s.length();
        while(i<n && s[i]==' '){
            i++;
        }
        if(i<n && (s[i]=='-' || s[i]=='+')){
             sign = (s[i] == '-') ? -1 : 1;
             i++;
        }
        while(i<n && isdigit(s[i])){
            int digit = s[i] - '0';
            if(ans>(INT_MAX - digit) / 10){
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            ans=ans*10+digit;
            i++;    
        }
        return ans*sign;
    }

int main(){

	string s = "  -042";
	int  ans=partialcorrect(s);
	int  myatoi= myAtoi(s);
	cout<<ans;
	cout<<endl;
	//cout<<s;
	return 0;


}