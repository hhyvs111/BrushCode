// #include<bits/stdc++.h>
// using namespace std;
// int main(){
// 	int n;
// 	cin >> n;
// 	int ans = 0;
// 	for(int i = 1;i <= n/2;i++) {
// 		int sum = 0;
// 		for(int j = i; sum < n;j++){
// 			sum += j;
// 			if(sum == n)
// 				ans++;
// 		}
// 	}
// 	cout << ans + 1 << endl;
// 	return 0;
// }


#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int ans = 0;

	if(n == 3){
		cout << 2 << endl;
		return 0;
	}
	int tmp;
	for(int i = 1;i < sqrt(2 * n);i++){
		if( 2 * n % i == 0){
			tmp = 2* n / i - i + 1;
			if( tmp > 0 && tmp % 2 == 0)
				ans++;
		}
	}
	cout << ans - 1 << endl;
	return 0;

}