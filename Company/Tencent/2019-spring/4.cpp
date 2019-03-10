// #include<iostream>
// #include<cstdio>
// #include<vector>
// using namespace std;
// const int maxn = 100000;
// int num[maxn];
// bool isok(vector<int> &nums);

// int main()
// {
//     int n,m;
//     scanf("%d %d", &n, &m);
//     vector<int> nums(m+1);
//     for(int i = 0;i < n;i++)
//     {
//         scanf("%d", &num[i]);
//     }
//     for(int i = 0;i < m;i++)
//     {
//         nums[num[i]]++;
//     }
//     //维护一个连续数组，如果首位相等则
//     int minSize = n;
//     int windowSize = m;
//     if(isok(nums))
//     {
//         printf("%d\n", m);
//         return 0;
//     }
//     cout << "test" << endl;
//     for(int j = windowSize; j < n;j++)
//     {
//         nums.resize(windowSize);
//         for(int k = 0;k < windowSize;k++)
//         {
//             nums[num[k]]++;
//         }
//         for(int i = 0; i < n - j;i++)
//         {
//             cout << num[i + j] << " " << num[i] << endl;
//             nums[num[i + j]]++;
//             nums[num[i]]--;
//             if(isok(nums))
//             {
//                 if(windowSize < minSize)
//                         minSize  = windowSize;
//             }
//         }
//     }
    
//     printf("%d\n", minSize);
//    return 0;
// }

// bool isok(vector<int> &nums)
// {
//     for(int i = 1;i <= nums.size();i++)
//     {
//         // cout << nums[i] << endl;
//         if(nums[i] == 0)
//             return false;
//     }
//     return true;
// }


#include <bits/stdc++.h>
using namespace std;

queue<int> q;
int cnt[2005];
int n, m, tot;
int ans = 1e9;
int main() {
    cin >> n >> m;
    tot = 0;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        q.push(x);
        //入队的时候x++，对应气球颜色加1
        cnt[x]++;
        //如果当前为1，则气球颜色总数加1
        if(cnt[x] == 1) tot++;
        //如果气球对应颜色数 超过1，那么可以将队头出队，也就是第一个进入的
        while(cnt[q.front()] > 1 || q.front() == 0) {
            cout << q.front() << endl;
            cnt[q.front()]--;
            //如果队头剪完后为0？感觉肯定是2才进来啊，怎么1
            if(cnt[q.front()] == 0) tot--;
            q.pop();
        }
        if(tot == m && ans > q.size()) ans = q.size();
    }
    if(ans != 1000000000) cout << ans;
    else cout << -1;
    return 0;
}
