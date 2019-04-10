#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> monster(n, 0);
    vector<int> money(n, 0);
    for(int i = 0;i<n;i++)
    {
        cin>>monster[i];
    }
    long long cur = 0;
    int ans = 0;
    for(int i = 0;i < n;i++)
    {
        cin >> money[i];
        if(cur < monster[i]){
            cur += monster[i];
            ans += money[i];
        }
    }
    cout << ans << endl;
    return 0;
}