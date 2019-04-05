#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> m >> n;
    vector<int> a(n+1, 0);
    for(int i = 1;i <= n;i++)
    {
        int num;
        cin >> num;
        a[i] = num;
    }
    sort(a.begin(), a.end());  //注意排序
    if(a[1] != 1){
        cout << "-1" << endl;
        return 0;
    }
    int sum = 0,ans = 0;
    for(;;){
        if(sum >= m){
            cout << ans << endl;
            return 0;
        }
        for(int i = n;i >= 1;i--)   //从大到小
            if(a[i] <= sum+1){   
                sum += a[i];
                ans++;
                break;
            }       
    }
    return 0;
}