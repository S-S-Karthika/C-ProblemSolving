#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

int longestSubstring(string s ,int k){
	unordered_map<char,int>occur;
	int start=0,n=s.size(),maxlen=-1;
	for(int i=0;i<n;i++){
		occur[s[i]]++;
		while(occur.size()>k){
			occur[s[start]]--;
			if(occur[s[start]]==0)occur.erase(s[start]);
			start++;
		}
		if(occur.size()==k){
			maxlen = max(maxlen,i-start+1);
		}
	}
return maxlen;
}


int longest(string s, int k) {
    int curr[26] = {0};
    int left = 0;
    int maxlen = 0;
    int unique = 0;

    for (int i = 0; i < s.size(); i++) {
        if (curr[s[i] - 'a'] == 0)
            unique++;
        curr[s[i] - 'a']++;

        while (unique > k) {
            curr[s[left] - 'a']--;
            if (curr[s[left] - 'a'] == 0)
                unique--;
            left++;
        }

        if (unique == k)
            maxlen = max(maxlen, i - left + 1);
    }

    return maxlen;
}

	int curr[26]={0};
	int left =0;
	int maxlen=0;
	for(int i=0;i<s.size();i++){
		curr[s[i]-'a']++;
		int length = sizeof(s) / sizeof(s[0]);
		if(length==k)maxlen=max(maxlen,i-left+1);
		while(length>k){
			curr[s[left]-'a']--;
			left++;
		}
	}
	return maxlen;

}

int main(){

	string s = "aabacbebebe";
	//string s = "aaaabbbbbbbb";
        int k =3;
	int count =longestSubstring(s,k);
	int count1 =longest(s,k);
	cout<<"The Longest Substring with K Uniques "<<count;
	cout<<"The Longest Substring with K Uniques "<<count1;
	return 0;

}