#include <bits/stdc++.h>

using namespace std;

vector<int>vec[100005];

int vis[100005];
void dfs(int now,int r){
    vis[now]=1;
    if(vec[now].size() == 1){
        return;
    }
    for(int i=0;i<vec[now].size();i++){
        if(vec[now][i] == r)continue;
        dfs(vec[now][i],now);
    }
    return ;
}
int main(){
    int n,m,k,u,v;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<k;i++){
        scanf("%d%d",&u,&v);
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    int res=0;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            res++;
            continue;
        }
        dfs(i,-1);
    }
    printf("%d\n",res-1);
    return 0;

}