#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& num, int low, int high){
	int privot = num[low];
	while(low < high){
		while(low < high && num[high] >= privot)
			high--;
		swap(num[low], num[high]);
		while(low < high && num[low] <= privot)
			low++;
		swap(num[low], num[high]);
	}
	return low;
}
void quickSort(vector<int>& num, int low, int high){
	if(low < high){
		int mid = partition(num, low, high);
		quickSort(num, low, mid - 1);
		quickSort(num, mid + 1, high);
	}
	
}


int main()
{
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i = 0;i < n;i++){
		cin >> nums[i];
	}
	quickSort(nums, 0, n - 1);
	for(auto i : nums){
		cout << i << " ";
	}
	cout << endl;
	return 0;
}