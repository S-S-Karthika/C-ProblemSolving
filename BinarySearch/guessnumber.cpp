#include<iostream>
#include<vector>
using namespace std;

int guess(vector<int>& arr,int num){
    int low =0;
    int high = arr.size()-1;
    while (low<=high)
    {
        int mid = low+(high-low)/2;
        if(arr[mid]==num){
            return 1;
        }else if( arr[mid]<num){
            low = mid + 1;
            return 0;
        }else{
            high = mid - 1;
            return -1;
        }
    }
    return -2;
}


void guessnumber (vector<int> &arr,int number){
    int num;
    cout<<"Enter the gussed number ";
    while (true)
    {
        cin>>num;

        if(guess(arr,num)== -1){
            cout<<"Enter greater number";
        }else if (guess(arr,num)== 0)
        {
            cout<<"Enter lesser number";
        }else{
        cout<<"correct number"; 
        break;
        }
    }
    
  
    

}


int main(){
    int findnum =34;
    vector<int> array = {12,23,34,45,56};
    guessnumber(array,findnum);
    return 0;
     
}