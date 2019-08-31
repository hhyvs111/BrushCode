#include <bits/stdc++.h>

using namespace std;

int helper(vector<int> &vec, int b, int e) {

	vector<int> sub;
	for(int i = b; i  < e;i++) {
		
	}


}

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	vector<int> vec(n);

	for(int i = 0;i < n;i++){
		scanf("%d", &vec[i]);

	}
	//集合内的位置不超过k，那么就是在固定位置选
	int maxNum = 0;
	
	for(int i = 0;i < n;i++) {
		for(int j = i - k;j < n;j++) {

			int nowNum = vec[i];
			int p = j;
			int d = m - 1;
			if(p < 0)
				continue;
			while(d--) {
				if(p == i)
					p++;
				nowNum +=  vec[p];
				p++;
			}
			if(nowNum > maxNum)
				maxNum = nowNum;
			// cout << i << " "<<nowNum << endl;
		}

	}
	printf("%d\n", maxNum);
	return 0;
}