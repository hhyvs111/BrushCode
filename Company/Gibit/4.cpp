
#include <iostream>
#include <ctime>
using namespace std;
 
int G[5][5];
int visited[5][5];
int n = 5;
void euler(int u) {
  for (int v = 0; v < n; v++) {
    if (G[u][v] && ! visited[u][v]) {
      cout << u << "->" << v << endl;
      visited[u][v] = visited[v][u] = 1;
      euler(v);
    }
  }
}
 
int main() {
  G[1][2] = G[2][1] = G[1][3] = G[3][1] = 1;
  G[2][4] = G[4][2] = G[3][4] = G[4][3] = 1;
  euler(1);
  return 0;
}
