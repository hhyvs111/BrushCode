#include<bits/stdc++.h>

using namespace std;


int main() {
	//报数题，去重就好了
	int n, m;
	cin >> n >> m;

	vector<int> v(n);
	map<int,int> Map1;

	for(int i = 0;i < n;i++) {
		cin >> v[i];
		Map1[v[i]]++;
	}

	vector<int> ans;
	for(int i = 0;i < n;i ++) {
		if(Map1[v[i]] > m)
			continue;

		ans.push_back(v[i]);
	}
	for(int i = 0;i < ans.size() - 1; i++){
		cout << ans[i] << " ";
	}
	cout << ans[ans.size() - 1] << endl;

	return 0;
}