#include <iostream>
#include <stack>
#include <climits>
using namespace std;

class minimumstack
{
private:
    stack<int>mini;
    int minimum;
public:
    MinStack(){
       minimum = INT_MAX; 
    }

    void push(int val){
    if(mini.empty()){
        mini.push(val);
        minimum = val;

    }else{
        if(val>minimum){
            mini.push(val);
            cout<<"the pushed value is "<<val<< endl;
        }else{
            
            mini.push(2*val-minimum);
            minimum=val;
            cout<<"the pushed value is "<<minimum<< endl;
        }
    }
  }

   void pop(){
    if(mini.empty()){
        return ;
    }
     int topval = mini.top();
     mini.pop();
     if(topval<minimum){
        minimum = 2*minimum-topval;
     }  

  }

    int top(){
     if (mini.empty()) return -1;

        int topVal = mini.top();
        if (topVal < minimum) {
            return minimum; 
        } else {
            return topVal;
        }
  }

  int getmin(){
    if (mini.empty()) return -1;
        return minimum;
    }
    
};






int main(){
    minimumstack minstack;
    minstack.push(10);
    minstack.push(20);
    minstack.push(9);
    minstack.push(12);
    minstack.push(16);
    cout<<"the minimum of the stack is "<<minstack.getmin()<<endl;
    minstack.pop();
     cout<<"the top of the stack is "<<minstack.top()<<endl;
    minstack.pop();
     cout<<"the minimum of the stack is "<<minstack.getmin()<<endl;
    minstack.pop();

    return 0;
}