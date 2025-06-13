#include<iostream>
using namespace std;


void tower(int n,string source,string helper,string destination){
if(n==0)return;

tower(n-1,source,destination,helper);
cout<<"Rod move from "<<n<<" from "<<source<<" to "<<destination<<endl;
tower(n-1,helper,source,destination);

}


int main(){

	int n=3;
	tower(n,"A","B","C");//source ,helper,destination
	return 0;
}