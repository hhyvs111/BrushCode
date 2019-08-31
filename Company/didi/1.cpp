#include <bits/stdc++.h>

using namespace std;

int main() {
	//首先保证的是表达式值不变，而且这里没有括号，那么就是这个乘号要小心了

	int n;
	scanf("%d", &n);
	vector<int> num(n);
	vector<char> str(n - 1);
	//这里只能交换相邻的数，那么就要比较一下了

	for(int i = 0; i < n;i++) {
		if(i < n - 1)
			scanf("%d %c", &num[i], &str[i]);
		else 
			scanf("%d", &num[i]);
	}

	int i = 0;
	while(i < n - 1) {
		//遇到了+
		if(str[i] == '+' || str[i] == '-') {
			int cnt = 0;
			int j = i;
			while( j < n-1){
				//最后一个数字
				if(str[j] == '+' || str[j] == '-') {
					j++;
					cnt++;
				}else {
					break;
				}
			}
			if(j == n - 1)
				cnt++;
			if(cnt == 1) {
				if(num[i] > num[i+1])
					swap(num[i], num[i+1]);
			} else {
				sort(num.begin() + i, num.begin() + i + cnt);
			}
			i = j;
		} else if(str[i] == '*' || str[i] == '/') {
			int cnt = 0;
			int j = i;
			while(j < n - 1){
				if(str[j] == '*' || str[i] == '/') {
					j++;
					cnt++;

				} else {
					break;
				}
			}
			if(j == n - 1)
				cnt++;
			if(cnt == 1) {
				if(num[i] > num[i+1])
					swap(num[i], num[i+1]);
			} else {
				sort(num.begin() + i, num.begin() + i + cnt);
			}
			
			i = j;

		} 
		
	}
	for(int i = 0; i < n;i++) {
		if(i < n - 1)
			cout << num[i] << " " << str[i] << " ";
		else
			cout << num[i] << endl;
	}
	return 0;
}
