#include <iostream>
#include <stack>
using namespace std;


string PostfixtoInfix(string postfix){
    stack<string>answer;

    for (char letter : postfix)
    {
        if((letter>='a' && letter<='z')||(letter>='A' && letter<='Z')||(letter>='0' && letter<='9')){
            answer.push(string(1,letter));
        }else if (letter =='+' || letter =='-' || letter =='*' || letter =='/' || letter =='^')
        {
           string insert1 = answer.top();
           answer.pop();
           string insert2 = answer.top();
           answer.pop();

           string conversion = '('+insert2+letter+insert1+')';
           answer.push(conversion);
        }
        
    }
    return answer.top();
    

}

int main(){
    string postfix ;
    postfix="abcde^*-+";
    cout<<" The postfix is "<<postfix<<endl;
    cout<<" The infix is "<<PostfixtoInfix(postfix)<<endl;

}