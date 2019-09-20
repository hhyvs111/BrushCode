#include<bits/stdc++.h>
using namespace std;
int coor[500][500];


void dfs(vector<vector<int>>& ans, int x, int y) {
	if(coor[x][y] == 1)
		return;

	if(x >500 || x < -500 || y > 500 | y < -500)


	ans[x][y] = min(dfs(ans, x-1,y),dfs(ans,)
}
int main() {
	int x,y,n;

	memset(coor, 0, sizeof(coor));

	for(int i = 0;i < n;i++) {
		int x, y;
		cin >> x >> y;
		coor[x][y] == 1;
	}

	vector<vector<int>> ans(500, vector<int> (500, 0));




}