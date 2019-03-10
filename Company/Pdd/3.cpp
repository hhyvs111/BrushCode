#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct bank
{
    ll pos;
    ll num;
};
int cmp(bank a, bank b)
{
    return a.num > b.num;
}
bank b[200000];
int main()
{
    ll n,d;
    scanf("%lld %lld",&n, &d);
    for(int i = 0;i < n;i++)
    {
        scanf("%lld %lld",&b[i].pos, &b[i].num );
    }
    sort(b,b+n,cmp);
    for(int i = 0;i < n;i++)
        printf("%d %d\n", b[i].pos, b[i].num);
    ll ans = b[0].num;
    ll nowPos = b[0].pos;
    for(int i = 1 ; i < n;i++)
    {
        if(abs(b[i].pos - nowPos) >= d)
        {
            ans+=b[i].num;
            nowPos = b[i].pos;
            break;
        }
    }
    printf("%lld\n", ans);
    return 0;
}