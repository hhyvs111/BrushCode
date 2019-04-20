#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--){
		int N;
		cin >> N;
		int cnt = 0;
		while(N-- >= 0){
			int ans = 0;
			string str;
			getline(cin, str);
			for(int i = 0; i < str.size();i++){
				if(str[i] == '#'){
					continue;
				}
				//判断是否是[]()组合
				else if(str[i] == '['){
					int tmp = 0 ;
					int j = i + 1;
					for(;str[j] != ']';j++){
						ans++;
					}
					// cout << "[] " << ans << endl;
					// cout << str[j + 1] << endl;
					if(str[++j] == '('){
						for(; str[j] !=')';j++){
							// cout << str[j];
						}
						// cout << endl;
					}
					//直接跳到这里
					i = j;
				}
				else if(str[i] == '+'){
					continue;
				}
				else{
					ans++;
				}
			}
			cnt += ans;
			// cout << str << " " << ans << " " << cnt << endl;

		}
		cout << cnt << endl;
	}
	return 0;
}
