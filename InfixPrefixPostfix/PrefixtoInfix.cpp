#include <iostream>
#include <stack>
#include<algorithm>
#include<cctype>
using namespace std;


string PrefixtoInfix(string prefix){
    stack<string>answer;
    int i = prefix.length()-1;

    while (i>=0) 
    {
        if((prefix[i]>='a' && prefix[i]<='z')||(prefix[i]>='A' && prefix[i]<='Z')||(prefix[i]>='0' && prefix[i]<='9')){
            answer.push(string(1,prefix[i]));
        }else 
        {
           string insert1 = answer.top();
           answer.pop();
           string insert2 = answer.top();
           answer.pop();

           string conversion = '('+insert1+prefix[i]+insert2+')';
           answer.push(conversion);
        }
        i--;
        
    }
    return answer.top();
    

}

int main(){
    string prefix ;
    // prefix="-ab";
    // prefix="*+abc";
    // prefix="-*AB/CD";
    prefix="/+A*BC-DE";
    cout<<" The prefix is "<<prefix<<endl;
    cout<<" The infix is "<<PrefixtoInfix(prefix)<<endl;

}