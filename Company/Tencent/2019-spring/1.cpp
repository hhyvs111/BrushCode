#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 1e8 + 10;
int n, m;
int main()
{
    scanf("%d %d", &n, &m);
    int ans = 0;
    while(m)
    {
        // cout << m << endl;
        if(m >= n)
        {
            m -= n;
            ans++;
        }
        else
            n--;
    }
    printf("%d\n", ans);
}