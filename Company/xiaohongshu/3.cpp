

#include<bits/stdc++.h>
using namespace std;

int dp[1000][2];
int main() {

	//首先这个题尼玛是不能相邻的，那么排序肯定就不能用了。这里只能弄一个排列组合了。不过好像也不能简单的用这个单双来操作。
	//这个有点像之前那个什么二分法？
	//这些题肯定尼玛都是改编的，但是自己可能做不出来，十分的尴尬啊弟弟。

	int n;
	cin >> n;
	vector<int> num(n);

	for(int i = 1;i <= n;i++)
		cin >> num[i];

	//一开始只能选第一个或者第二个
	dp[1][0] = num[1];
	dp[1][1] = 1;

	dp[2][0] = num[2];
	dp[2][1] = 1;
	for(int i = 3; i <= num.size();i++) {

		//选第i个
		//的确是挺巧妙的啊
		//如果第一个第三个大于第二，就相加并加1
		if(dp[i-2][0] + num[i] > dp[i-1][0]) {
			dp[i][0] = dp[i-2][0] + num[i];
			dp[i][1] = dp[i-2][1] + 1;
		}else{
			//如果加起来更小，那么就不更新。

			//一开始搞错了，日了dj。
			
			dp[i][0] = dp[i-1][0];
			dp[i][1] = dp[i-1][1];
		}

	}

	cout << dp[num.size()][0] << " " << dp[num.size()][1]  << endl;

	// int excl = 0, incl = num[0];
	// int excl_new;
	// //这里可以计算出这个最大值，但是好像不能计算这有多少个值？
	// for(int i = 1;i < num.size();i++) {
	// 	excl_new = (excl > incl) ? excl:incl;
	// 	incl = excl + num[i];
	// 	excl = excl_new;
	// }

	// int ans;
	// // cout << incl << " " << excl << endl;
	// ans = (incl>excl)?incl:excl;

	//其实就两种，一种偶数的情况话肯定是输出/2
	//奇数的情况就要判断是否是边缘的值
	
	// if (cnt%2 == 0) {
	// 	cout << ans << " "<< cnt << endl;
	// } else {
	// 	if (incl > excl)
	// 		cout << ans << " " << cnt + 1 << endl;
	// 	else 
	// 		cout << ans << " " << cnt << endl;
	// }
	return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// int main() {

// 	//首先这个题尼玛是不能相邻的，那么排序肯定就不能用了。这里只能弄一个排列组合了。不过好像也不能简单的用这个单双来操作。
// 	//这个有点像之前那个什么二分法？
// 	//这些题肯定尼玛都是改编的，但是自己可能做不出来，十分的尴尬啊弟弟。

// 	int n;
// 	cin >> n;
// 	vector<int> num(n);

// 	for(int i = 0;i < n;i++)
// 		cin >> num[i];

// 	if (num.size() == 1) {
// 		cout << num[0] << " " << 1 << endl;
// 		return 0;
// 	}
// 	if (num.size() == 2) {
// 		if (num[0] > num[1]) {
// 			cout << num[0] << " " << 1 << endl;
// 			return 0;
// 		}else {
// 			cout << num[1] << " " << 1 << endl;
// 			return 0;
// 		}
// 	}
// 	if (num.size() == 3) {
// 		if (num[0] + num[2] > num[1]){
// 			cout << num[0] + num[2] << " " << 2 <<endl;
// 			return 0; 
// 		} else {
// 			cout << num[1] << " " << 1 << endl;
// 			return 0;
// 		}
// 	}
// 	int excl = 0, incl = num[0];
// 	int excl_new;
// 	int cnt = 0;
// 	//这里可以计算出这个最大值，但是好像不能计算这有多少个值？
// 	for(int i = 1;i < num.size();i++) {

// 		excl_new = (excl > incl) ? excl:incl;
// 		if (excl < incl) {
// 			cnt++;
// 		}
// 		incl = excl + num[i];
// 		excl = excl_new;
// 	}

// 	int ans;

// 	//判断一下三个的情况
// 	//偶数情况和奇数情况有点区别啊，但是应该是一样的，我感觉是没区别，就算是偶数也是可以的吧
// 	cout << ans << " "<< cnt << endl;
// 	return 0;
// }