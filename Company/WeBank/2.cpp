#include<bits/stdc++.h>
using namespace std;

bool fun(int n){
    for(int i = 2; i <= sqrt(n);i++){
        if(n%i==0)
            return false;
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    int cnt = 0;
    for(int i = 2;i <= n;i++){
        if(fun(i)){
            int tmp = i;
            while(tmp <= n){
                cnt++;
                tmp *= i;
            }
        }
    }
    cout << cnt << endl;
}
