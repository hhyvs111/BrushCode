#include<bits/stdc++.h>
using namespace std;
int main()
{
    int stuNum, candyNum;
    cin >> stuNum;
    vector<int> students, candys;
    while(stuNum--)
    {
        int stu;
        scanf("%d", &stu);
        students.push_back(stu);
    }
    cin >> candyNum;
    while(candyNum--)
    {
        int candy;
        scanf("%d", &candy);
        candys.push_back(candy);
    }
    sort(candys.begin(), candys.end());
    sort(students.begin(), students.end());
    int ans = 0;
    //贪心法思想，尽可能的将小的给小的，把糖果消耗完
    for(int i = 0, j = 0; i < candys.size() && j < students.size(); i++)
    {
        //如果这个糖果不能不能满足，那么后面的都不能满足吧。
        if(candys[i] >= students[j])
        {
            j++;
            ans++;
        }
    }
        cout << ans << endl;
}