#include<bits/stdc++.h>
using namespace std;

long long  gcd(long long  a, long long  b){
	while(a%b != 0){
		long long  tmp = a;
		a = b;
		b = tmp % a;
	}
	return b;
}

long long lcm(long long  a, long long  b){
	return a*b / gcd(a, b);
}
int main(){
	long long  n;
	cin >> n;
	// long long maxNum = 0;
	// long long left = 2;
	// long long right = n;
	cout << lcm(n, n-1) - gcd(n, n-1) << endl;
	// for(int i = 2;i <= n;i++) {
	// 	for(int j = 2;j <= n;j++) {
	// 		cout << " " << i << " " << j << endl;
 //            cout << lcm(i, j) << " " << gcd(i, j) << endl;
	// 		maxNum = max(maxNum, lcm(i, j) - gcd(i, j));
	// 	}
	// }
	// cout << maxNum << endl;
	return 0;
}