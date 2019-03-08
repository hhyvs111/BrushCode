#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        vector<int> nums;
        for(int i = 0; i < n;i++)
        {
            int num;
            scanf("%d", &num);
            nums.push_back(num);
        }
        sort(nums.begin(), nums.end());
        int d = nums[1] - nums[0];
        cout << d <<endl;
        for(int i = 1 ;i < n - 1;i++)
        {
            cout << nums[i+1] - nums[i] << endl;
            if(d != (nums[i+1] - nums[i]))
            {
                printf("Impossible\n");
                break;
            }
        }
        printf("Possible\n");
    }
    return 0;
}