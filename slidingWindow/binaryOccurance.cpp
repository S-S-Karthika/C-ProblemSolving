#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

int binaryOccurance(string s ,int k){
unordered_set<string>occur;
for(int i=0;i<s.size()-k;i++){
occur.insert(s.substr(i,k));
}
if(occur.size() == 1<<k){
	return 1;
}else{
	return 0;
}
}

int main(){

	string s = "111111101";
        int k =2;
	int count =binaryOccurance(s,k);
	cout<<"The Binary Occurance of the String "<<count;
	return 0;

}