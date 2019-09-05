#include<bits/stdc++.h>
using namespace std;

const int Maxn = 5e5+10;

int num[Maxn];

int main() {
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> num[i];

	int maxNum = 0;
	for(int i = 1;i <= n;i++) {
		int minNum = num[i];
		int cnt = num[i];
		for(int j = i - 1; j >= 1;j--) {
			if(num[j] > minNum) 
				cnt += num[j];
			else
				break;
		}
		for(int j = i + 1; j <= n;j++) {
			if(num[j] >= minNum)
				cnt += num[j];
			else
				break;
		}
		maxNum = maxNum > cnt * minNum ? maxNum : cnt * minNum;
	} 
	cout << maxNum << endl;
	return 0;
}