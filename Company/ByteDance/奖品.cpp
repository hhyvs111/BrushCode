#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        vector<int> nums(n,0);
        for(int i = 0 ; i < n;i++)
            cin >> nums[i];

        vector<int> ans(n,1);
        for(int i = 0 ; i < n - 1;i++)
        {
            if(nums[i] < nums[i+1])
                ans[i+1] = ans[i] + 1;
        }
        if(nums[n-1] < nums[0])
            ans[0] = ans[n-1] + 1; 
        for(int i = n - 1;i >= 0; i--)
        {
            if(nums[i - 1] > nums[i])
                ans[i - 1] = max(nums[i - 1], nums[i] + 1);
        }
        if(nums[n - 1] > nums[0])
            ans[n - 1] = max(nums[n - 1], nums[0] + 1);
        cout << accumulate(ans.begin(), ans.end(), 0) << endl;
    }
    // for (int kk = 0; kk < T; ++kk) {
    //     int n;
    //     cin >> n;
    //     vector<int> vi(n);
    //     for (int i = 0; i < n; ++i) cin >> vi[i];
    //     vector<int> ans(n, 0);
    //     int index = 0, nums = 0;
    //     while (nums < n) {
    //         for (int i = 0; i < n; ++i)
    //             if (ans[i] == 0) {
    //                 index = i;
    //                 break;
    //             }
    //         for (int i = 0; i < n; ++i) if (ans[i] == 0 && vi[index] >= vi[i]) index = i;
    //         ans[index] = 1;
    //         nums++;
    //         int flag = index, p = index + 1, q = index - 1;
    //         while (1) {
    //             if (p >= n) p = p - n;
    //             if (ans[p] != 0) break;
    //             if (vi[p] > vi[flag]) {
    //                 ans[p] = ans[flag] + 1;
    //                 nums++;
    //                 flag = p;
    //                 p++;
    //             } else break;
    //         }
    //         flag = index;
    //         while (1) {
    //             if (q < 0) q = q + n;
    //             if (ans[q] != 0) break;
    //             if (vi[q] > vi[flag]) {
    //                 ans[q] = ans[flag] + 1;
    //                 nums++;
    //                 flag = q;
    //                 q--;
    //             } else break;
    //         }
    //     }
        // cout << accumulate(ans.begin(), ans.end(), 0) << endl;
    return 0;
}