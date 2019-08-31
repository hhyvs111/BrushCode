#include <bits/stdc++.h>

using namespace std;
int mins[325][150000];
int dp[325][150000];
int a[150000],b[1500000];
vector<int>mp[150000];


int main()
{
    int n,A,B;
    scanf("%d%d%d",&n,&A,&B);
    
    for(int i=1;i<=100000;i++)
        mp[i].clear();
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
        mp[b[i]].push_back(i);
    }
    memset(mins,0,sizeof(mins));
    for(int i=1;i<=300;i++)
    {
        for(int j=0;j<=n;j++)
        {
            mins[i][j]=0x3f3f3f3f;
        }
    }
    int output=0;
    for(int i=1;i<=300;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int pre=mins[i-1][j-1];
            mins[i][j]=mins[i][j-1];
            int res=-1;
            int l=0;
            int r=mp[a[j]].size()-1;
            while(r-l>=0)
            {
                int mid=(l+r)/2;
                if(mp[a[j]][mid]>pre)
                {
                    r=mid-1;
                    res=mp[a[j]][mid];
                }
                    else l=mid+1;
                }
                if(res==-1)
                    continue;
                if(i*B+j+res<=A)
                    output=i;
                mins[i][j]=min(mins[i][j-1],res);
            }
        }
        printf("%d\n",output);
        return 0;
}
