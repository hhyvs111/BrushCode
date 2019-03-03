class Solution {
public:
int largestRectangleArea(vector<int> &height) {
        //维护一个递增栈，栈的底部肯定是高度最小的。
        height.push_back(0); // 添加虚拟矩形条
        stack<int> st;
        int n = height.size();
        int maxArea = 0;
        int h, w;

        for (int i = 0; i < n; i++) 
            //如果栈顶比当前的i的高度小，直接push
            //这里存的是高度的位置，不是具体高度
            if (st.empty() || height[st.top()] < height[i])
                st.push(i);
            //如果大
            else {
                //如果栈顶比i大，计算当前的值
                while (!st.empty() && height[i] <= height[st.top()]) {
                    //高度是当前栈顶的高度
                    h = height[st.top()];
                    //将栈顶弹出
                    st.pop();
                    //如果栈为空，那么宽度就是i，否则是i - 减去栈顶的位置+ 1.
                    //比如如果栈顶是位置0，这个时候进来一个1，且Height[0] > height[1]
                    //这个时候栈顶为空，因为0已经弹走了，然后宽度就是1 ，如果栈不为空。
                    
                    //这里只维护1个位置，不用管其他的地方
                    //1. 我们只需要在辅助栈保存矩形的右边界坐标即可，不需要保存高度，因为可以通过右边界坐标得到（height[i] ），也不需要保存左边界坐标，因为上一个矩形的右边界坐标+1就是当前矩形的左边界。

                    //2. 在直方图最后添加一个高度为0的虚拟矩形条，这样保证一次遍历之后栈里面的矩形都被正确处理过了，否则需要再重复一遍。
                    w = st.empty() ? i : i - (st.top() + 1);
                    maxArea = max(maxArea, h * w);
                }
                st.push(i);
            }
            return maxArea;
        }
};