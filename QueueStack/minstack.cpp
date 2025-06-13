#include<bits/stdc++.h>
using namespace std;


class MinStack{

private:
	stack<pair<int,int>>st;

public:
	MinStack(){}

	void push(int val){
		if(st.empty()){
			st.push({val,val});
		}else{
			st.push({val,min(val,st.top().second)});
		}
	}


	void pop(){
		if(!st.empty())st.pop();
	}

	int top(){
		if(!st.empty()){
			return st.top().first;
		}
		return -1;
	}

	int getMin(){
		if(!st.empty()){
			return st.top().second;
		}
		return -1;
	}

};

class MinStack{

private:
	stack<int>st;
	int mini;

public:
	MinStack(){
		while (st.empty() == false) st.pop();
     		 mini = INT_MAX;
	}

	void push(int val){
		if(st.empty()){
			mini=val;
			st.push(val);
		}
		else{
			if(val>mini){
				st.push(val);
			}else{
				st.push(2*val-mini);
				mini =val;
			}
		}
	}


	void pop(){
		if(st.empty())return;
		if(st.top()<mini){
			mini=2*mini-st.top();
		}
		st.pop();
	}

	int top(){
		if(st.empty())return -1;
		if(st.top()<mini){
			return mini;
		}
		return st.top();
	}

	int getMin(){
		return mini;
	}

};



int main() {
    vector<string> operations = {"MinStack", "push", "push", "push", "getMin", "pop", "top", "getMin"};
    vector<vector<int>> values = {{}, {-2}, {0}, {-3}, {}, {}, {}, {}};
    vector<string> result;

    MinStack* minStack = nullptr;

    for (int i = 0; i < operations.size(); i++) {
        string op = operations[i];

        if (op == "MinStack") {
            minStack = new MinStack();
            result.push_back("null");
        }
        else if (op == "push") {
            minStack->push(values[i][0]);
            result.push_back("null");
        }
        else if (op == "pop") {
            minStack->pop();
            result.push_back("null");
        }
        else if (op == "top") {
            result.push_back(to_string(minStack->top()));
        }
        else if (op == "getMin") {
            result.push_back(to_string(minStack->getMin()));
        }
    }

    // Print the result
    cout << "[";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i != result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}