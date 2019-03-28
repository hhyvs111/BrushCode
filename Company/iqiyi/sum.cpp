#include<bits/stdc++.h>
using namespace std;

int main()
{
    double n, m;
    while(cin >> n >> m){
        double cnt = 0;
        while(m--){
            cnt += n;
            n = sqrt(n);
        }
        printf("%.2f",cnt);
        
    }
}