#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main()

{
	vector<int> nums {1,2,3,4,5,1,2,3};
	auto it1 = nums.end();
	cout << *(nums.end() - 2) << endl;
	std::set<int> test(nums.begin(), nums.end());
	// long l = -2;
	// cout << *(test.end() + l) << endl;
	return 0;
}