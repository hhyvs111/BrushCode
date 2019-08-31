#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;


int dp[maxn],a[maxn];
int Search(int len,int x);

int main()
{
    int n;
    cin >> n;
    cin >> a[0];
    dp[0]=a[0];
    int len=1,j;
    for(int i=1;i<n;i++)
    {
        cin >> a[i];
        if(a[i]<dp[0]) 
            j=0;
        else if(a[i]>=dp[len-1]) 
            j=len++;
        else 
            j=Search(len,a[i]);
        dp[j]=a[i];
    }
    cout << len;
}

int Search(int len,int x)
{
    int l=0,r=len-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(x>=dp[mid-1]&&x<dp[mid]) 
            return mid;
        else if(x<dp[mid-1]) 
            r=mid-1;
        else 
            l=mid+1;
    }
    return l;
}