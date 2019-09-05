#include<bits/stdc++.h>
using namespace std;
int main() {
	char op[3] = {'d', 'l', 'r'};
	int n;
	cin >> n;
	string a, b;
	while(n--) {
		cin >> a >> b;
		int len = a.size();
		int x = pow(3, len);
		vector<int> res;
		for(int i = 0;i < x;i++) {
			deque<char> d;
			string tmp = "";
			int l = 0, r = len - 1;
			int op = i;
			while(op) {
				if(op % 3 == 0) {
					i++;
				}else if (op % 3 == 1) {
					d.push_front(a[l]);
					l++;
				} else {
					d.push_back(a[r]);
					r--;
				}
				op /= 3;
			}
			while( !d.empty()) {
				tmp += d.front();
				d.pop_front();
			}
			if(tmp == b) {
				res.push_back(i);
			}
		}
		cout << "{" << endl;
		for(int i = 0; i < res.size();i++) {
			stack<int> st;
			int c = 0;
			while(res[i]) {
				st.push(res[i]%3);
				res[i] /= 3;
				c++;
			}
			while(c != 3) {
				st.push(0);
				c++;
			}
			while(!st.empty()) {
				cout << op[st.top()];
				st.pop();
				if(st.empty()) 
					cout << endl;
				else 
					cout << " ";
			}
		}
		cout << "}" << endl;
	}

}