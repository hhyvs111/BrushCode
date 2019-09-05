#include<bits/stdc++.h>
using namespace std;


struct cus {
	int a;
	int b;
};

bool cmp(cus i, cus j) {
	if(i.a != j.a)
		return i.a > j.a;
	else
		return i.b < j.b;
}
int main(){
	int n;
	cin >> n;
	vector<cus> vec(n);
	for(int i = 0;i < n;i++) {
		cin >> vec[i].a >> vec[i].b;
	}

	sort(vec.begin(), vec.end(), cmp);

	for(int i = 0;i < n;i++) {
		cout << vec[i].a << " " << vec[i].b << endl;
	}

	int ans = 0;
	for(int i = n - 1;i >= 0;i--) {
		ans += vec[i].a * (i + 1 - 1) + vec[i].b *(n - i-1);
	}
	cout << ans << endl;
	return 0;

}