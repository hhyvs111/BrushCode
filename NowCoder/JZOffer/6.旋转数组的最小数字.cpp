#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    //二分思想    
    int minNumberInRotateArray(vector<int> rotateArray) {
        int size = rotateArray.size();
        if(size == 0)
            return 0;
        int left = 0, right = size -1;
        
        while(left < right)
        {
            int mid = (left + right) / 2;
           //如果right比mid小，那么最小值肯定在右边区域
            if(rotateArray[right] < rotateArray[mid])
            {
                left = mid + 1;
            }
            //如果相等，那么就需要一个个试
            else if(rotateArray[right] == rotateArray[mid])
            {
                right --;
            }
            //如果right比mid大，那么最小值肯定在左边，因为根据有序关系，不会出现12304这种样例
            else
            {
                right = mid;
            }
        }
        return rotateArray[left];
    }
};

int main()
{
    Solution s;
    //vector<int> test = {3, 4, 5, 1, 2};
    std::vector<int> test = {1,2};
    cout << s.minNumberInRotateArray(test) << endl;
    return 0;
}