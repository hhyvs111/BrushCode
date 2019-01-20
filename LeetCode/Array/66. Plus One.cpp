class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        //牛逼的思维！
        for (int i = n - 1; i >= 0; --i)
        {
            //如果是9则为0
            if (digits[i] == 9)
            {
                digits[i] = 0;
            }
            //如果第一个不是9则直接返回
            //如果第二个不是9那么加1返回
            else
            {
                digits[i]++;
                return digits;
            }
        }
        //如果能走到这里，那么说明都是9
		digits[0] =1;
		digits.push_back(0);
        return digits;
    }
};