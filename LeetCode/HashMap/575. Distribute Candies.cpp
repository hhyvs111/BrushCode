class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        //妹妹能获得最多的糖果，不同数字代表不同的糖果，主要是给妹妹尽可能多的不重复的糖果。
        //计算数组不同的数组个数，和子数组长度（也就是这个总长度的一半，因为是偶数长度的数组）。
        //如果只有1种糖果，那么妹妹就最多获得一种，如果糖果种数大于总糖果的一半，那么妹妹最多获得总糖果一半的糖数。
        unordered_set<int> setCandies(candies.begin(), candies.end());
        return setCandies.size() < candies.size() / 2 ? setCandies.size() : candies.size() / 2;
         
    }
};