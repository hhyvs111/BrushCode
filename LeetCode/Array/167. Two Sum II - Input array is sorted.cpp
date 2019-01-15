class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        //两个指针遍历
        
        while(numbers[i]  + numbers[j] != target)
        {
            //如果大于target则左移j
            if(numbers[i]  + numbers[j] > target)
                j--;
            //小于则右移i,使数字增大
            else
                i++;
        }
        return vector<int>{i+1,j+1};
    }
};