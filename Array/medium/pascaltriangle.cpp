//Example 1:
//Input Format: N = 5, r = 5, c = 3
//Result: 6 (for variation 1)
//1 4 6 4 1 (for variation 2)

//1 
//1 1 
//1 2 1 
//1 3 3 1 
//1 4 6 4 1    (for variation 3)
// vector<vector<int>>array={{1},{1,1},{1,2,1},{1,3,3,1},{1,4,6,4,1}};
//Explanation: There are 5 rows in the output matrix. Each row is formed using the logic of Pascal’s triangle.



#include<iostream>
#include<vector>
using namespace std;







//-----------------------------------------------------------------------------------------

int generateindividual(int row,int col){
	int ans=1;
	for(int i=1;i<col;i++){
		ans*=(row-i);
		ans/=i;
	}
return ans;
}

//--------------------------------------------------------------------------------------------------

vector<int>generatearray(int rows){
	vector<int>ans;
	
	for(int i=1;i<=rows;i++){
		ans.push_back(generateindividual(rows,i));
	}
return ans;
}

//---------------------------------------------------------------------------------------------------


vector<vector<int>>generatepascal(int rows){
	vector<vector<int>>ans;
	for(int i=0;i<rows;i++){
		ans.push_back(generatearray(i+1));
	}
return ans;

}


int main(){

int numRows=5;
int row=4,col=2;
int rows=5;

vector<vector<int>>array= generatepascal(numRows);
int getindividual =generateindividual(row,col);
vector<int>getarray =generatearray(rows);



cout<<getindividual<<endl;

for(int num:getarray){
     cout<<num<<" ";
}
cout<<endl;


cout<<"["<<endl;
for(auto& subset : array){
	cout<<"[ ";
	for(int num : subset){
	cout<<num;

	}
	cout<<" ]"<<endl;
}
cout<<" ]";
return 0;
}