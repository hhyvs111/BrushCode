#include<bits/stdc++.h>
using namespace std;
int n;
int a[51], b[51];
int cmp1(int a,int b)
{
    return b>a;
}
int main()
{
    scanf("%d", &n);
    for(int i = 0 ; i < n;i++)
        scanf("%d",&a[i]);
    for(int i = 0 ;i < n;i++)
        scanf("%d", &b[i]);
    sort(a, a+n);
    sort(b, b+n);
    int ans = 0;
    for(int i = 0; i < n;i++)
    {
        ans += a[i] * b[n - i - 1];
    }
    cout << ans << endl;
}