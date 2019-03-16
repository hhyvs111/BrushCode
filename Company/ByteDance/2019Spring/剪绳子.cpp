#include<cstdio> 
#include<iostream>
using namespace std;

#define eps 0.00001
int num[100050];
int n, m;

//每个绳子除以答案，看是否能满足m的要求,第一个2.5传进来5/2.5等于2，所以这里的ans是4正好，但是答案不对。
int check(double l) {
    int ans = 0;    
    for (int i=0; i<n; i++) {
        ans += (int)((double)num[i] / l);
    }
    cout << "    " << ans << endl;
    return ans;
}

int main()
{
    cin >> n >> m;
    double minn = 0.0, maxn = 0.0;
    //求最长的绳子
    for (int i=0; i<n; i++) {
        scanf("%d", &num[i]);
        if (maxn < num[i]) maxn = (double)num[i];
    }

    double mid;
    //找到中点，看是否满足
    while (maxn - minn >= eps) {
        mid = (minn + maxn) / 2;
         cout << minn << " " << maxn << endl;
            cout << mid << endl;

        if (m > check(mid)) {
            // 需求 > 能做的，太长了 
            maxn = mid;
            continue; 
        } else {
            // 需求 < 能做的，太短了 
            minn = mid;
            continue; 
        }
    } 
    printf("%.2lf\n", mid);
    return 0;
} 