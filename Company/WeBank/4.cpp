

#include<bits/stdc++.h>
using namespace std;
int is_palindrome(int n)
{
    int count = 0;
    int m1,m2;
    m1 = n;
    m2 = 0;
    for (count = 0; m1 != 0; count++)
    m1 >>= 1;
    m1 = n;
    for (; count > 0; count--)
    {
        m2 <<= 1;
        m2 += (m1 & 1);
        m1 >>= 1;
    }
    if (m2 == n)
        return 1;
    else
        return 0;
}
int main()
{
    long long int n;
    long long int ans = 0;
    cin >> n;
    for(int i = 0 ; i <= n;i++)
    {
        if(is_palindrome(i))
            ans ++;
    }
    cout << ans << endl;
    return 0;
}

