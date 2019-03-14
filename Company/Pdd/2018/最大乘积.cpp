#include<iostream>
#include<cstdio>
#include<limits.h>
using namespace std;
int main()
{
 
    long long  Max1, Max2, Max3, Min1, Min2;
    Max1 = Max2 = Max3 = INT_MIN;
    Min1 = Min2 = INT_MAX;
    int n;
    cin >> n;
    long long  num;
    for(int i = 0 ; i < n; i++)
    {
        scanf("%lld", &num);
        if(num < Min1)
        {
            Min2 = Min1;
            Min1 = num;
        }
        else if(num < Min2)
        {
            Min2 = num;
        }
        if(num > Max1)
        {
            Max3 = Max2;
            Max2 = Max1;
            Max1 = num;
        }
        else if(num > Max2)
        {
            Max3 = Max2;
            Max2 = num;
        }
        else if(num > Max3)
        {
            Max3 = num;
        }
    }
    long long ans = Max3*Max2*Max1 > Max1*Min2*Min1 ? Max3*Max2*Max1 : Max1*Min2*Min1;
    cout << ans << endl;
}

//思路就是找到最大的三个数和最小的两个数，因为这两个数可能是负数，这样将最大的数和最小的两个负数相乘就是最大值。在找值的时候要按顺序替换对应的值.
