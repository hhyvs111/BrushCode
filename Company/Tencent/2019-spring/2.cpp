#include<iostream>
#include<cstdio>
using namespace std;
typedef long long LL;
int main()
{
    int q;
    scanf("%d", &q);
    while(q--)
    {
        LL l,r;
        scanf("%lld %lld", &l, &r);
        if(l == r)
        {
            if(l%2)
                printf("%lld\n", -l);
            else
                printf("%lld\n", l);
            continue;
        }
        LL qianR, qianL;
        if(l%2)
            qianL = -(l+1)/2;
        else
            qianL = l/2;
        if(r%2)
            qianR = -(r+1)/2;
        else
            qianR = r/2;
        
        // cout << qianR <<endl;
        // cout << qianL <<endl;
        LL ans;
        if(l%2)
            ans = qianR + qianL + 1;
        else
            ans = qianR + qianL;
        printf("%lld\n", ans);
    }
    return 0;
}