#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a[20001];
	a[0] = 1;
	int digit = 1;
	for(int i = 2;i <= n;i++) {
		int num = 0;

		for(int j = 0;j < digit;j++) {
			int tmp = a[j] * i + num;
			a[j] = tmp % 10;
			num = tmp / 10;
		}
		while(num) {
			a[digit] = num % 10;
			num = num / 10;
			digit++;
		}

	}
	// cout << digit << endl;
	for(int i = 0;i < digit;i++){
		// cout << a[i] << endl;
		if(a[i] != 0){
			cout << a[i] << endl;
			break;
		}
	}
	return 0;
}