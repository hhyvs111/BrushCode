class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //当天买的股票不能当天卖，卖出股票后需要有冷却期一天。
        //这个应该是一个经典的dp题，但是好像不是那么容易啊。
        //找到状态转换方程
        if(prices.size() == 0) return 0;
        //维护连个状态，主要是这个一个买，一个卖。
        int buy = INT_MIN, pre_buy = 0, sell = 0, pre_sell = 0;
        //冷冻期的价值就是sell[i-1]，因为这个时候
        //buy[i]  = max(sell[i-2] - price, buy[i-1]) 
        //sell[i] = max(buy[i-1] + price, sell[i-1])
        //这里的sell[i-2]就是这个pre_sell，所以用2个值就能记录！
        for (int price : prices) {
            pre_buy = buy;
            buy = max(pre_sell - price, pre_buy);
            pre_sell = sell;
            sell = max(pre_buy + price, pre_sell);
        }
        return sell;
    }
};