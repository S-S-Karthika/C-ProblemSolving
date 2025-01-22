#include<bits/stdc++.h>
using namespace std;

vector<int> Eratosethenes(int number){
    vector<bool>answer(number+1,true);
    answer[0]=false;
    answer[1]=false;
    for(int i =2;i<=sqrt(number);i++){
        if(answer[i]){  
        for (int j = i*i; j <=number ; j+=i)
            {
                answer[j]=false;  
            }
        }
        
    }
    vector<int>result;
    for(int i =2;i<=number;i++){
        if(answer[i]){
            result.push_back(i);
        }
    }
    return result;
}

int main(){
    int number;
    cout<<"Enter a Number : ";
    cin>>number;
    vector<int> ans=Eratosethenes(number);
    for(auto i : ans){
       cout<<i<<endl;
    }
    return 0;   

   
}