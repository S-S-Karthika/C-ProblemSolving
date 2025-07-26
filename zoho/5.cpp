//find-number-currency-notes-sum-upto-given-amount

#include<iostream>
using namespace std;
#include<string>

string hexi(char ch){
    switch (toupper(ch))
    {
    case '0':return "0000";
    case '1':return "0001";
    case '2':return "0010";
    case '3':return "0011";
    case '4':return "0100";
    case '5':return "0101";
    case '6':return "0110";
    case '7':return "0111";
    case '8':return "1000";
    case '9':return "1001";
    case 'A':return "1010";
    case 'B':return "1011";
    case 'C':return "1100";

    default:
        return "Invalid";
    }
}


int main(){
    string hex="1aCb2";
    string ans="";
    for(char ch: hex){
        string curr=hexi(ch);
        if(curr=="Invalid"){
            cout<<"it is invalid";
            return 0;
        }
        ans+=curr;
    }
    cout<<ans;
}