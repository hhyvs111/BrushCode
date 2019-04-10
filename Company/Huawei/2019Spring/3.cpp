#include<bits/stdc++.h>
using namespace std;
long long maxnum = 1e9;
void DFS(vector<vector<long long> > &grid, vector<vector<bool> > &visited, int x, int y, int z, int w, int& ans) {
    if (x < 0 || x >= grid.size()) return;
    if (y < 0 || y >= grid[0].size()) return;
    if(x == z && y == w){
        ans++;
        return;
    }
    int now = grid[x][y];
    if (visited[x][y]) return;
        visited[x][y] = true;
    if(x - 1 >=0 && grid[x - 1][y] > now )DFS(grid, visited, x - 1, y, z, w, ans);
    if(x + 1 < grid.size() && grid[x + 1][y] > now )DFS(grid, visited, x + 1, y, z, w, ans);
    if(y - 1 >= 0 && grid[x][y - 1] > now )DFS(grid, visited, x, y - 1, z, w, ans);
    if(y + 1 <= grid[0].size() && grid[x][y + 1] > now )DFS(grid, visited, x, y + 1, z, w, ans);
    visited[x][y] = false;
}
int main()
{
    int n,m;
    cin >> n >> m;
    vector< vector<long long> > g(n, vector<long long>(m, 0));
    vector<vector<bool> > visited(n, vector<bool>(m, false));

    for(int i = 0;i < n;i++){
        for(int j = 0; j < m;j++)
            cin >> g[i][j];
    }
    int x,y,z,w;
    cin >> x >> y >> z >> w;
    int ans = 0;
    DFS(g, visited, x, y, z, w, ans);
     ans = ans%maxnum;
    cout << ans  << endl;
    return 0;
}