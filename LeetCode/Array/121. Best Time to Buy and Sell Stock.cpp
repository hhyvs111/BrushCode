class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int maxProfit = 0;
        int minPrice = prices[0], maxPrice = 0;
        int indexMax = 0, indexMin = 0;
        for(int i = 0;i < prices.size();i++)
        {
            if(prices[i] > maxPrice)
            {
                maxPrice = prices[i];
                indexMax = i;
            }
            
            if(prices[i] < minPrice)
            {
                minPrice = prices[i];
                indexMin = i;
                //当最小值出现的时候，如果最大值的下标小于最小值的下标，那么重置最大值
                if(indexMin > indexMax)
                    maxPrice = 0;
            }
              
            
            if(maxPrice - minPrice > maxProfit)
                maxProfit = maxPrice - minPrice;
        }
        return maxProfit;
    }
};