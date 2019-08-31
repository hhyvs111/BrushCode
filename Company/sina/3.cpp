#include <bits/stdc++.h>

using namespace std;

int a[1005];
int d[1005][1005];
vector<int> r;
int main(){
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0;i < n;i++){
		scanf("%d", &a[i]);
	}
	int res =0;
	d[0][1] = a[0];
	d[0][0] = 0;
	for(int i = 1; i < n;i++) {
		for(int j = 1;j <= k && j <=i;j++) {
			for(int l = 1; l <= m;l++) {
				d[i][l] = max(d[i][l], d[i-j][l-1] + a[i]);
			} 
		}
		res = max(res, d[i][m]);
	}
	printf("%d\n", res);
	return 0;
}