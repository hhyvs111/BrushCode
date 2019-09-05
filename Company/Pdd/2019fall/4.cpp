#include<bits/stdc++.h>
using namespace std;


int main() {
	int n, m, k;

	scanf("%d%d%d", &n, &m, &k);
	// vector<int> vec;
	// for(int i = 0; i < n ; i++) {
	// 	for(int j = 0;j < m;j++) {
	// 		a[i][j] = (i+1) * (j+1);
	// 		vec.push_back(a[i][j]);
	// 	}
	// }
    
 // //    for(int i = 0; i < n ; i++) {
	// // 	for(int j = 0;j < m;j++) {
	// // 		cout << a[i][j] ;
	// // 	}
 // //        cout << endl;
	// // }

	// sort(vec.begin(), vec.end());
	int p = m - k/4;
	int q = n - k/4;

	printf("%d\n", p * q);
	return 0;
}