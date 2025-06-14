#include<iostream>
#include<stack>
#include <algorithm>
#include<cctype>
using namespace std;

int priority(char letter){
        if(letter == '^'){
            return 3 ;
        }else if (letter == '*' || letter == '/')
        {
           return 2 ;
        }else if (letter=='+'|| letter =='-')
        {
            return 1;
        }else{
            return 0;
        }
        
        
}

string InfixtoPrefix( string infix){
    reverse(infix.begin(),infix.end());
    stack<char> symbol;
    string answer = "";

    for(char letter : infix){
        if((letter>='a' && letter<='z')||(letter>='A' && letter<='Z')||(letter>='0' && letter<='9')){
            answer+=letter;
        }else if (letter==')')
        {
            symbol.push(letter);
        }else if (letter=='(')
        {
            while (symbol.top() != ')'  &&  !symbol.empty())
            {
               answer+=symbol.top();
               symbol.pop();
            }
            symbol.pop();
            
        }else 
        {
           while (!symbol.empty() && priority(letter)<=priority(symbol.top()))
           {
            answer+=symbol.top();
            symbol.pop();
           }
           symbol.push(letter);
           
        }    
    }

    while (!symbol.empty())
    {
       answer+=symbol.top();
       symbol.pop();
    }

    reverse(answer.begin() , answer.end());
    return answer;
    

}




int main(){
    string infix;
    infix="a+b*(c^d-e)";
    // infix ="abcd^e-*+";
    // infix="abcde^*-+";

    cout<<"The Infix is "<< infix<<endl;
    
    string prefix = InfixtoPrefix(infix);

    cout<<"The prefix is "<<prefix <<endl;
    return 0;


}