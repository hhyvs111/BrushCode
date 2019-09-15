#include<bits/stdc++.h>
using namespace std;


int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int n, int m){
	if(x >= n || x < 0 || y >=m || y < 0 ){
		return 0;
	}

	if(visited[x][y] == true || grid[x][y] != 1)
		return 0;
	visited[x][y] = true;

	return dfs(grid, visited, x - 1, y, n, m) + 
		   dfs(grid, visited, x + 1, y, n, m) +
		   dfs(grid, visited, x, y - 1, n, m) +
		   dfs(grid, visited, x, y + 1, n, m) + 1;
}
int main(){
	string str;
	cin >> str;
	istringstream is(str);
	int in;
	char ch;
	vector<int> nums;
	while(is >> in) {
		nums.push_back(in);
		is >> ch;
	}
	vector<vector<int>> grid;
	vector<vector<bool>> visited(nums[0], vector<bool> (nums[1], false));
	for(int i = 0;i < nums[0];i++) {
		string s;
		cin >> s;
		istringstream is(s);
		vector<int> vec;
		while(is >> in) {
			vec.push_back(in);
			is >> ch;
		}

		grid.push_back(vec);

	}
	// for(int i = 0;i < nums[0];i++) {
	// 	for(int j = 0;j < nums[1];j++) {
	// 		cout << grid[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	int maxNum = 0;
	for(int i = 0;i < nums[0];i++) {
		for(int j = 0;j < nums[1];j++) {
			if(!visited[i][j] && grid[i][j] == 1){
				int num = dfs(grid, visited, i, j, nums[0], nums[1]);
				// cout << num << endl;
				maxNum = max(maxNum, num);
			}

		}
	}
	cout << maxNum << endl;


}