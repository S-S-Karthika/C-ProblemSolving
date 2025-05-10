#include<iostream>
#include<string>
using namespace std;


bool rotatestring(string s,string goal){
	if(s.size() != goal.size()){
            return false;
        }
	string rotate=s+s;
	if(rotate.find(goal)!=string::npos){
		return true;
	}else{
		return false;
	}

	
	
}

int main(){

	string s = "abcde", goal = "cdeab";
	if(rotatestring(s,goal))cout<<"true";
	else cout<<"false";
	return 0;


}