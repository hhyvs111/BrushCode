#include<bits/stdc++.h>
using namespace std;
#define maxn 100000+100
#define INF 0x3f3f3f3f

int a[maxn],b[maxn],ans;
vector<int> idx[maxn];
int f[305][maxn];

int main()
{
    int n,s,e;
    cin>>n>>s>>e;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int j=1;j<=n;j++)
        scanf("%d",&b[j]),idx[b[j]].push_back(j);
    for(int i=1;i<=n;i++)
        idx[a[i]].push_back(INF);

    for(int i=1;i<=s/e;i++)
        f[i][0]=INF;
    memset(f[0],0,sizeof(f[0]));
    for(int i=1;i<=s/e;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int k=lower_bound(idx[a[j]].begin(),idx[a[j]].end(),min(f[i-1][j-1]+1,INF))-idx[a[j]].begin();
            f[i][j]=min(idx[a[j]][k],f[i][j-1]);
            if(j+f[i][j]+i*e<=s)ans=i;
        }
    }   
    cout<<ans<<endl;
    return 0; 
}