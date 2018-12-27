class Solution {
public:
    int Fibonacci(int n) {
        int first = 0;
        int second = 1;
        //动态规划思想，还是要学习一下。
        int result = n;
        for(int i = 2; i<=n; i++){
            result = first + second;
            first = second;
            second = result;
        }
        return result;
    }
};
