#include<iostream>
#include<string>
#include<algorithm>
using namespace std;



string optimal(const string &s) {
        string output;
        string ans;
       for(auto i = s.rbegin() ; i!= s.rend();++i){
        if(*i == ' '){
             if (!output.empty()) {
                reverse(output.begin(),output.end());
                if (!ans.empty()) ans += " ";
                ans+=output;
                output.clear();
             }
        }else{
            output+=*i; 
        } 
       } 
        // Add the last word (if any)
        if (!output.empty()) {
            reverse(output.begin(), output.end());
            if (!ans.empty()) ans += " ";
            ans += output;
        }
       return ans;
}



string reversewords(const string &s){
	string currans,ans;
	int n=s.size();
	for(int i=n-1;i>=0;i--){
		if(s[i]==' '){
			reverse(currans.begin(),currans.end());
			ans += currans + ' ';
			currans.clear();
		}else{
			currans.push_back(s[i]);
		}
	}
	if(!currans.empty()){
		reverse(currans.begin(),currans.end());
		 ans += currans;
	}
	if(!ans.empty() && ans.back() == ' ')
	       ans.pop_back();

	return ans;
}

int main(){

	//string s = "a good   example";
	string s ="  hello world  ";

	string num =reversewords(s);
	string ans =optimal(s);
	cout<<num<<endl;
	cout<<ans;
	return 0;


}