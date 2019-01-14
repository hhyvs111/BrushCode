class Solution {
public:
    int fib(int N) {
       int f = 0, g = 1;
        while(N--) {
            g += f;
            f = g - f;
        }
        return f;
    }
};