#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k;
	scanf("%d%d", &n, &k);

	vector<int> vec(n);
	for(int i = 0;i < n;i++) {
		scanf("%d", &vec[i]);
	}
	sort(vec.begin(), vec.end()); 
	int ans = 0;
	for(int i = 0;i < n - 1;i++) {
		if(vec[i+1] - vec[i] <= k) {
			ans++;
			i++;
		}
	}
	printf("%d\n", ans);
	return 0;
}