// #include <bits/stdc++.h>
// using namespace std;

// int countDuplicates(vector<int> numbers) {
//     //计算重复的数字的个数
//     int nums = numbers[0];
//     unordered_map<int, int> numSet;
//     int cnt = 0;
//     for(int i = 1;i <= nums;i++)
//     {
//         numSet[numbers[i]]++;
//     }
//     for(auto it = numSet.begin(); it != numSet.end();it++)
//     {
//         if(it->second > 1)
//             cnt++;
//     }
//     return cnt;

// }

// int main()
// {
//     int n;
//     while(cin >> n)
//     {
//         vector<int> nums;
//         for(int i = 0 ;i <= n;i++){
//             int num;
//             cin>>num;
//             nums.push_back(num);
//         }
//         cout << countDuplicates(nums) << endl;;
//     }
//     return 0;
// }


#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int index;
    cin>>index;
    set<int>vec;
    map<int,int>mp;
    while(index--)
    {
        int n;
        cin>>n;
        mp[n]++;
        if(mp[n]>1)
            vec.insert(n);
    }
    cout<<vec.size()<<endl;
    return 0;
}