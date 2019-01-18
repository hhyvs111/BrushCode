class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //爬楼梯，可以从下标为0或者1开始爬，然后你可以消耗当前下标当值走1或者2步，看你怎么走。
        
        //其实就两种走法，保持局部最优就好了
        int f1 = 0, f2 = 0;
        for(int i = cost.size() - 1; i >= 0;--i)
        {
            int f0 = cost[i] + min(f1,f2);
            f2 = f1;
            f1 = f0;
        }
        return min(f1,f2);

        // //主要是考虑最后4个元素
        // while(index < size)
        // {
        //     if(index == size - )
        //     if(cost[index + 1] > cost[index + 2])
        //     {
        //         index += 2;
        //         min
        //     }
        //     if((cost[index] + cost[index + 2]) > cost[index + 1])
        //     {
        //         index++;
        //         minCost += cost[index];
        //     }
        //     else
        //     {
        //         index+=2;
        //         minCost +=
        //     }
        // }
    }
};