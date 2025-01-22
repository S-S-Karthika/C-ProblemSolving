// input:100
//output:2,5


#include<bits/stdc++.h>
using namespace std;

vector<int> UniqueFactor(int number)
{
    vector<int> answer;
    
    for (int i = 2; i <= sqrt(number); i++)
    {
        while(number%i==0){
        answer.push_back(i);
        number/=i;
      }
    }
    if(number>2){
        answer.push_back(number);
    }
    answer.erase(unique(answer.begin(),answer.end()),answer.end()) ;
    return answer;
    
}

int main(){
    int number;
    cout<<"Enter a Number : ";
    cin>>number;
    vector<int> ans=UniqueFactor(number);
    for(auto i : ans){
       cout<<i<<endl;
    }
    return 0;   

   
}