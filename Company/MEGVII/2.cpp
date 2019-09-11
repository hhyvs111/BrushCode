#include<bits/stdc++.h>
using namespace std;
int main() {
    long long  k;
    string str;
    cin >> k >> str;
    vector<int> ch(26,0);
    long  long cnt = 0;
    long long  left = 0, right = 0;
    long long  ans = 0;
    for(long long  i = 0;i < str.size();i++){
        if(ch[str[i] - 'a'] > 0) {
        	ch[str[i] - 'a']++;
            right = i+1;
        }
        else{
            //滑动不了，这个时候就判断是否超过了cnt
            if(cnt < k){
                cnt++;
                ch[str[i] - 'a']++;
                right = i + 1;
                // cout << right << endl;
            }else{
            	long long  j = left;
            	for(;j < i;j++) {
            		ch[str[j]-'a']--;
            		if(ch[str[j] -'a'] == 0){
            			j++;
            			break;
            		}
            	}
            	// cout <<"test " <<  j << endl;
            	right = i + 1;
            	left = j+1;
            	cnt--;
            }
        }
        cout << left << " " << right << endl;
        for(int k = left;k < right;k++) {
        	cout << str[k];
        }
        cout << endl;
        ans = max(ans, right-left);
    }
    cout << ans << endl;
    return 0;
}