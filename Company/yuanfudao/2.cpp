#include<bits/stdc++.h>

using namespace std;


int main() {
    
    int c;
    cin >> c;
    
    while(c--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0;i < n;i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());

        int res = 0;
        for(int i = n - 1;i > 0;i-=3) {
            res += v[i - 2];
        }

        cout << res << endl;
        
        // for(;i < n;){
        //     if(v[i] <= 0) 
        //         i++;
        //     else
        //         break;
        // }
        // long long  res = 1;
        // if(i > n - 3){
        //     cout << 0 << endl;
        //     continue;
        // } else {
        //     res *= v[i];
        //     i+=3;
        // }


        // //每三个一组那么就是以最小的为基础，3个一排，剩下的乘以三个
        // int t = 0;
        // for(;i < n;i++) {
        //     if (t == 0) {
        //         t = 1;
        //         res *= 3;
        //     }
                
        //     res *= v[i];
        // }
        // // cout << i << endl;
        // //如果还有剩下的，那么就直接乘以这个
        // // if(i < n)
        // //     res *= v[i];
        // cout << res << endl;
    }
     return 0;   
}