#include<bits/stdc++.h>
using namespace std;
int main() {
	int num[105];
	int n;
	scanf("%d", &n);
	for(int i = 0;i < n;i++) 
		scanf("%d", &num[i]);

	
	double ans = 0;
	for(int i = 0;i < n;i++) {
		for(int j = 1;j <= num[i];j++) {
			double tmp = 1;
			for(int k = 0; k < n;k++) {
				if (i != k) {
					if(j <= num[i]) {
						k > i ? tmp *= ((j*1.0) / num[i]):tmp *= ((j-1)*1.0 / num[i]);
					}
				}
			}
			ans += tmp * j / num[i];
		}
	}
	printf("%.2f\n", ans);
	return 0;
}