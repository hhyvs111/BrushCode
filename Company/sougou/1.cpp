#include<bits/stdc++.h>
using namespace std;

struct value
{
	unsigned int val;
	int t;
};
int main() {
	int n;
	cin >> n;
	map<string, value> m;
	string str;
	unsigned int val;
	int cnt = 0;
	int time = 0;
	while(cin >> str >> val){
		auto iter = m.find(str);
		//没找到插入
		if(iter == m.end()){
			if(cnt < n) {
				value v;
				v.val = val;
				v.t = time;
				m.insert(pair<string, value>(str, v));
				cnt++;
			}else if (cnt == n){
				auto minIt = m.begin();
				int minTime = INT_MAX;
				for(auto it = m.begin(); it != m.end();it++) {
					if(it->second.t < minTime) {
						minIt = it;
						// cout << it->second.t << endl;
						minTime = it->second.t;
					}
				}
				cout << minIt->first << " " << minIt->second.val << endl;
				m.erase(minIt);
				value v;
				v.val = val;
				v.t = time;
				m.insert(pair<string, value>(str, v));
			}

			//找到了
		} else {
			// cout << iter->second.val << endl;
			if(iter->second.val < val){	
				iter->second.val = val;
				iter->second.t = time;
			}
		}
		time++;
	}
	return 0;
}