#include<bits/stdc++.h>
using namespace std;
int main(){
	//队列形变，如果能从一个队列转换为另一个队列，这里只能对其进行队头的出入。
	int n;
	cin >> n;
	int ans = 0;
	while(n--) {
		int number;
		cin >> number;


		//移动两次，前后移动一下，如果移动后相等应该就是没问题了
		vector<int> num1(number);
		vector<int> num2(number);
		cout << num1.size() << endl;

		for(int i = 0; i < number;i++) {
			cin >> num1[i];

		}



		for(int i = 0; i < number;i++) {
			cin >> num2[i];
		}


		sort(num1.begin(), num1.end());
		sort(num2.begin(), num2.end());
		for(int i = 0;i < number;i++) {
			cout << num1[i] << " ";
		}
		for(int i = 0;i < number;i++) {
			cout << num2[i] << " ";
		}
		//直接排序一下
		if (num1 == num2) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	return 0;

}