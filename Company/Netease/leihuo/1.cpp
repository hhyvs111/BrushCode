#include<bits/stdc++.h>
using namespace std;

struct rectangle
{
	int w;
	int h;
};

bool cmp(rectangle a, rectangle b) {
	if(a.w * a.h != b.w * b.h)
		return a.w * a.h < b.w * b.h;
	else {

		int k1 = max(a.w/a.h, a.h/a.w);

		int k2 = max(b.w/b.h, b.h/b.w);
		// cout << k1 << " " << k2 << endl;
		if(k1 != k2)
			return k1 < k2;
		else
			return a.w < b.w; 
	}
}
int main(){
	int n;
	cin >> n;
	vector<rectangle> rec(n);
	for(int i = 0;i < n;i++) {
		cin >> rec[i].w >> rec[i].h;
	}

	sort(rec.begin(), rec.end(), cmp);
	for(int i = 0;i < n;i++) {
		cout << rec[i].w << " " << rec[i].h;
		if(i != n-1)
			cout << " ";
		else
			cout << endl;
	}
	return 0;
}