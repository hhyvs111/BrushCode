class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        //怎么这种题总是感觉做不出来的感觉
        //经典dp
        int first = 1;
        int second = 2;
        for (int i = 3; i <= n; i++) {
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
    }
};