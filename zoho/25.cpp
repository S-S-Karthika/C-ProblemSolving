//Reverse the given string keeping the position of special characters intact

#include <bits/stdc++.h>
using namespace std;



int main(){
string str="AB$HJ&I";
int low=0,high=str.size()-1;
while(low<high){
	if(str[low]>='A' && str[low]<='Z' && str[high]>='A' && str[high]<='Z'){
		swap(str[low++],str[high--]);
	}else if(str[low]>='A' && str[low]<='Z'){
		high--;
	}else{
		low++;
	}
}
cout<<str<<endl;
string sequence="AB$HJ&I";
low=0,high=sequence.size()-1;
while(low<high){
	if(!isalpha(sequence[low]) ){
		low++;
	}else if(!isalpha(sequence[high])){
		high--;
	}else{
		swap(sequence[low++],sequence[high--]);
	}
}
cout<<sequence;
}


