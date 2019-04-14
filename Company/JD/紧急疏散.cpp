#include<bits/stdc++.h>
using namespace std;
//这题有点像是求树的最大深度啊，但是如何建树呢？
struct Edge
{
	int x;
	int y;
};
int main()
{
	int n;
	cin >> n;
	vector<Edge> edge(n);
	for(int i = 0;i < n;i++){
		cin >> edge[i].x >> edge[i].y;
	} 

	//东哥不能做你兄弟了
}