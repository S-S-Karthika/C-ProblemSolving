#include<iostream>
#include<string>

using namespace std;


void sortchar(const string &s){
	int n=s.size();
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			cout<<s.substr(i,j-i+1)<<endl;
		}
	}

}

int main(){

	string s = "aabbb";
	
	sortchar(s);
	
	return 0;


}