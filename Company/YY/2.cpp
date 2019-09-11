#include<bits/stdc++.h>
using namespace std;


void midOrder(vector<int>& num, int i) {
	if(i < num.size()){
		midOrder(num, 2*i+1);
		cout << num[i] << endl;
		midOrder(num, 2*i+2);
	}


}
int main() {

	int n;
	cin >> n;
	n = (int)pow(2, n)  - 1;
	// cout << n << endl;
	vector<int> num(n);
	for(int i = 0;i < n;i++) {
		cin >> num[i];
	}
	midOrder(num, 0);
	return 0;

}