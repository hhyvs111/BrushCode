class Solution {
public:
    int maxProfit(vector<int>& prices) {

        //看错题，原来是多个相加。只要保证前一个小于后一个就好了。题目没要求不能同一天买卖
        if(prices.size() <= 1) return 0;
        int total = 0;
        for(int i = 0 ; i < prices.size() - 1;i++)
        {
            if(prices[i+1] > prices[i]) total += (prices[i+1] - prices[i]);
        }
        return total;
    }
};