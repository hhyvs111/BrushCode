#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    int h = INT_MAX, l = 0;
    for(int i=0; i<m; i++)
    { 
        cin >> a[i];
        l = max(a[i], l);
    }
    int c, s;
    int cnt = 100;
    while(cnt--){
    
        int mid = (h+l)/2;
        c = 1;
        s = 0;
        for(int i = 0; i < m; i++){
        
            if(s + a[i] > mid){
            
                s += a[i];
                c++;
            }else{
                s = a[i];
            }
            
            if(s+a[i]<=mid)
            {
                s+=a[i];
            }else{
                s=a[i];
                c++;
            }

        }
        if(c > n){
            l = mid;
        }else {
            h = mid;
        }
    }
    cout << h << endl;
}