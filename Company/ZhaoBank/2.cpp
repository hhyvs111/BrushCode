#include<bits/stdc++.h>
using namespace std;

struct tree
{
	int val;
	tree* left;
	tree* right;
};

int dfs(vector<vector<int>>& tree, int root, int max, int len) {
	
}
int main() {
	int n;
	cin >> n;
	vector<vector<int>> tree(n);
	for(int i = 0;i < n-1;i++) {
		int x, y, val;
		cin >> x >> y >> val;
		tree[x][y] = val;
	}
}