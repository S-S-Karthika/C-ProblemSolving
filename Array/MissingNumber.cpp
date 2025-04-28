#include <iostream>
#include <vector>
#include<unordered_set>
#include<algorithm>//for sort()
using namespace std;

int main(){
    vector<int>arr= {3,0,1,2,5,6,7,8,9};
    int size=arr.size();
    int total=0;
    int n=(size*(size+1))/2;
    for(int num : arr){
        total+=num;
    }
    cout<<"The Missing Number is "<< n-total<<endl;
    return 0;
}