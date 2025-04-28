#include <iostream>
#include <vector>
#include<climits>
#include<algorithm>//for sort()
using namespace std;

class MaximumConsicutiveOnes
{

public:
  int maximumOnes(vector<int>&arr){
    int maxOnes=INT_MIN;
    int count=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==1){
            count++;
        }else{
            maxOnes=max(maxOnes,count);
            count=0;
        }    
    }
    maxOnes=max(maxOnes,count);
    return maxOnes;

  }
};

int main(){
    MaximumConsicutiveOnes maximum;
    vector<int>arr={1,1,1,0,0,1,1,1,1,1,1,1};
    int ans = maximum.maximumOnes(arr);
    cout<<"the maximum concecutive one is "<<ans<<endl;
    return 0;

}


