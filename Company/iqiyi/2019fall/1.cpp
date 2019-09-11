#include<bits/stdc++.h>
using namespace std;
long long ans = 10e9 + 7;


long long cnt = 0;

void helper(vector<int>& num, int begin, vector<int>& target, vector<int>& visited, bool status, vector<int>& out) {
	if(!status)
		return;
	if(begin == num.size()){
		// for(int i = 0;i < num.size() - 1;i++){
		// 	if((target[i] == 1 && num[i] < num[i+1]) || (target[i] == 0 && num[i] > num[i+1]))
		// 		return;
		// }
		cnt++;
		return;
	}


	// for(int i = 0;i < num.size();i++) {
	// 	if(visited[i] == 1)
	// 		continue;
	// 	visited[i] = 1;
	// 	out.push_back(num[i]);
	// 	if(begin > 0 && i < num.size() -1) {
	// 		cout << out.size() << endl;
	// 		cout << begin <<" " << target[i-1] << " " << out[i-1] << " out:" << out[i] << " i:" << i << endl;
	// 		if((target[i - 1] == 1 && out[i-1] < out[i]) || (target[i-1] == 0 && out[i-1] > out[i]))
	// 			status = false;
	// 	}
	// 	helper(num, begin+1, target, visited, status, out);
	// 	out.pop_back();
	// 	visited[i] = 0;
	// }
	for(int i = begin;i < num.size();i++) {
		swap(num[begin], num[i]);

		//剪枝一下
		for(int j = 0;j < i - 1;j++){
			if((target[j] == 1 && num[j] < num[j+1]) || (target[j] == 0 && num[j] > num[j+1])){

				status = false;
				// cout << begin <<" " << target[i-1] << " " << num[i-1] << " out:" << num[i] << " i:" << i << endl;
			}
		}
		helper(num, begin+1, target, visited, status, out);
		swap(num[begin], num[i]);

	}

}

int main(){
	int n;
	cin >> n;
	vector<int> target(n-1);
	for(int i = 0;i < n - 1;i++)
		cin >> target[i];
	vector<int> num(n);
	for(int i = 0;i < n;i++) {
		num[i] = i + 1;
		// cout << num[i] << endl;
	}
	vector<int> out, visited(num.size(), 0);

	helper(num, 0, target, visited, true, out);
	cout << cnt % ans << endl;
	return 0;
}

