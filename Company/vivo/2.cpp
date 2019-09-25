#include<bits/stdc++.h>
using namespace std;
int lastNum(int n, int m, int i) {
	if(i == 1)
		return (n+m-1)%n;
	else
		return (lastNum(n-1,m,i-1)+m)%n;
}
int main(){
	int n , m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		cout << lastNum(n, m, i) + 1 << " " << endl; 
	}
	return 0;
}