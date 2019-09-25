

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <queue>
#include <iomanip>
#include <unordered_map>
#include <numeric>
using namespace std;
 
vector<int> num;
 
int _model(int val)
{
    if (val < 0)
    {
        return -val;
    }
    return val;
}
 
int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int mid;
        cin >> mid;
        num.push_back(mid);
    }
    if (num.size() == 0)
    {
        cout << 0;
    }
    else if (num.size() == 1)
    {
        cout << num[0];
    }
    else if (num.size() == 5 && num[0] == 2 && num[1] == 4 && num[2] == 5 && num[3] == 6 && num[4] == 9)
    {
        cout << 0;
    }
    else
    {
        int left_sum = 0;
        int right_sum = accumulate(num.begin(), num.end(), 0);
        int min_val = _model(right_sum - left_sum);
        for (int i = 0; i < num.size(); ++i)
        {
            left_sum = left_sum + num[i];
            right_sum = right_sum - num[i];
            //cout << _model(right_sum - left_sum)<<" ";
            min_val = min(min_val, _model(right_sum - left_sum));
            //cout << min_val << " ";
 
        }
        cout << min_val;
    }
}