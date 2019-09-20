#include<bits/stdc++.h>
using namespace std;


int vec[100][100];
int visited[100][100];

void backTravse(int start, int end) {

}


void euler(int u, int n){
	for(int v = 0; v < n;v++) {
		if(vec[u][v] && visited[u][v] == 1) {
			visited[u][v] = visited[v][u] = 2;
			euler(v, n);
		}
	}
}
// bool isEnd(int j, int n) {
// 	int cnt = 0;
// 	for(int i = 0;i < n;i++){
// 		if(vec[j][i] == 1)
// 			cnt++;
// 	}
// 	if(cnt > 0)
// 		return false;
// 	return true;
// }
int main(){
	int n, m;
	cin >> n >> m;

	memset(vec, 0, sizeof(vec));
	memset(visited, 0, sizeof(visited));
	for(int i = 0;i < m;i++) {
		int x, y;
		cin >> x >> y;
		vec[x][y] = 1;
		vec[y][x] = 1;
		visited[x][y] = 1;
		visited[y][x] = 1;
	}

	int start, end;
	cin >> start >> end;

	vec[end][start] = 1;

	euler(start, n);

	vector<int> ans;
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {
			if(visited[i][j] == 2){
				ans.push_back(i);
				ans.push_back(j);
			}

		}
	}

	// queue<int> q;
	// q.push(start);

	// while(!q.empty()) {
	// 	int size = q.size();
	// 	cout << size << endl;
	// 	for(int i = 0;i < size;i++){
	// 		int node = q.front();
	// 		if(isEnd(node, n) && node != end) {
	// 			ans.push_back(node);
	// 			break;
	// 		}

	// 		for(int j = 0;j <= n;j++) {
	// 			if(vec[node][j] == 1)
	// 				q.push(j);
	// 		}

	// 		q.pop();
	// 	}

	// }
	for(int i = 0;i < ans.size() - 1;i++) {
		cout << ans[i] << " ";
	}
	cout << ans[ans.size() - 1] << endl;
}



