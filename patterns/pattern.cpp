#include<bits/stdc++.h>
using namespace std;

void print1(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << "* ";
        }
        cout << endl;
    }
cout<<endl;
}



void print2(int n){
	for(int i=0;i<n;i++){
	    for(int j=0;j<=i;j++){
		cout<<"* ";
	    }
	    cout<<endl;
	}
cout<<endl;

}



void print3(int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cout<<j<<" ";
		}
		cout<<endl;
	}
cout<<endl;
}



void print4(int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cout<<i<<" ";
		}
		cout<<endl;
	}
cout<<endl;
}


void print5(int n){

	for(int i=n;i>=1;i--){

		for(int j=0;j<i;j++){
		   cout<<"* ";
		}
		cout<<endl;
	}
cout<<endl;
}



void print6(int n){

	for(int i=n;i>=1;i--){

		for(int j=1;j<=i;j++){
		   cout<<j<<" ";
		}
		cout<<endl;
	}

}


void print7(int n){
	for(int i=1;i<=n;i++){
		//space
		for(int j=0;j<n-i;j++)cout<<" ";
		for(int j=0;j<i+(i-1);j++)cout<<"*";
		for(int j=0;j<n-i;j++)cout<<" ";
		cout<<endl;
	}

}


void print8(int n){
	for(int i=n;i>=1;i--){
		//space
		for(int j=0;j<n-i;j++)cout<<" ";
		for(int j=0;j<i+(i-1);j++)cout<<"*";
		for(int j=0;j<n-i;j++)cout<<" ";
		cout<<endl;
	}


}

void print9(int n){
	print7(n);
	print8(n);
}


void print10(int n){

	for(int i=0;i<2*n;i++){
		if(i<=n){
			for(int j=1;j<=i;j++)cout<<"*";
		}else{
			int num=n-(i%n);
			for(int j=1;j<=num;j++)cout<<"*";
		}
		cout<<endl;
	}

}



void print11(int n){

	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			if(i%2==0){
				int num=0;
				cout<<num;
				if(num==0)num++;
				else num--;
			}else{
				int num=1;
				cout<<num;
				if(num==0)num++;
				else num--;
			}
		}
	cout<<endl;
	}

}


void print12(int n){

	for(int i=1;i<=n;i++){
		int start=i%2==1?1:0;
		for(int j=1;j<=i;j++){
			cout<<start<<" ";
			start=1-start;
		}
		cout<<endl;
	}	

}



void print13(int n){
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			sum+=1;
			cout<<sum<<" ";
		}
		cout<<endl;
	}

}


void print14(int n){
	char ch='A';
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			char ans=ch+j;
			cout<<ans<<" ";
		}
	cout<<endl;
	}
}


void print15(int n){
	char ch='A';
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i;j++){
			char ans=ch+j;
			cout<<ans<<" ";
		}
	cout<<endl;
	}
}


void print16(int n){
	char ch ='A';
	for(int i=0;i<n;i++){
		char ans=ch+i;
		for(int j=0;j<=i;j++){
			cout<<ans<<" ";
		}
		cout<<endl;
	}
}


void print17(int n){

	for(int i=1;i<=n;i++){
		
		for(int j=1;j<=i;j++){
			cout<<j;
		}
		int space =2*(n-i);
		for(int k=1;k<=space;k++){
			cout<<" ";
		}
		
		for(int j=i;j>=1;j--){
			cout<<j;
		}
	cout<<endl;
	}

}


void print18(int n){

	char start='A'+n;
	for(int i=0;i<=n;i++){
		int num=i;
		for(int j=1;j<=i;j++){
			char ans=start-num;
			num--;
			cout<<ans;
		}
	cout<<endl;
	}

}


void print19(int n){

	for(int i=0;i<=n;i++){
		for(int j=1;j<n-i;j++)cout<<" ";
		char ch='A';
		for(int j=1;j<=i;j++)cout<<ch++;
		ch-=2;
		for(int j=1;j<i;j++)cout<<ch--;
	cout<<endl;
			
		
	}

}

void print21(int n){
	for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
	     if(i==0 || i==n-1 || j==0 || j==n-1){
		cout<<"*";
	     }else{
		cout<<" ";
	     }
	}
	cout<<endl;
	}
}


int main(){
    print1(5);
    print2(5);
    print3(5);	
    print4(5);
    print5(5);
    print6(5);
    cout<<endl;
    print7(5);
    cout<<endl;
    print8(5);
    cout<<endl;
    print9(5);
    cout<<endl;
    print10(5);
    cout<<endl;
    print11(5);
    cout<<endl;
    print12(5);
    cout<<endl;
    print13(5);
    cout<<endl;
    print14(5);
    cout<<endl;
    print15(5);
    cout<<endl;
    print16(5);
	cout<<endl;
    print17(5);	
	cout<<endl;
    print18(5);
	cout<<endl;
    print19(5);
	cout<<endl;
    print21(5);
    return 0;
}
