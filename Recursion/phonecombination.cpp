#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void combination(int pos,string input,vector<string>mpp,vector<string>&res,string s,int n){

if(pos==n){
res.push_back(s);
return;
}

int num=input[pos]-'0';
string curr=mpp[num-1];

for(int i=0;i<curr.size();i++){
s.push_back(curr[i]);
combination(pos+1,input,mpp,res,s,n);
s.pop_back();
}

}

void combo(string input){

vector<string>mpp={" ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
vector<string>res;
combination(0,input,mpp,res,"",input.size());

for(string s:res)cout<<s<<" ";

}


int main() {
    string input="23";
    combo(input);
}
