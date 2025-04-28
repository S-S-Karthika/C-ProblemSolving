#include<iostream>
#include<string>
#include<vector>
using namespace std;

string getpermutation( int n, int k){

	vector<int>nums;
	int fact=1;
	for(int i=1;i<n ;i++){
		nums.push_back(i);
		fact*=i;	
	}
	nums.push_back(n);
	k=k-1;
	string s="";
	while(true){
		s=s+to_string(nums[k/fact]);
		nums.erase(nums.begin()+k/fact);
		if(nums.size()==0){
			break;
		}
		k=k%fact;
		fact=fact/nums.size();
	}
	return s;
}

int main(){
	int k =17;
	int n=4;
	string s = getpermutation(n,k);
	cout << "Final permutation: " << s << endl;
	return 0;
}