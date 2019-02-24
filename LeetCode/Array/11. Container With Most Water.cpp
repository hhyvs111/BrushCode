class Solution {
public:
    int maxArea(vector<int>& height) {
        //找出最大面积，考虑三个值，一个是左边最高，然后右边较高，中间的距离要够宽
        //两个指针一个从前一个从后扫描，哪边小哪边前进
        int begin = 0;
        int end = height.size() - 1;
        int maxAreaSize = 0;
        while(begin != end)
        {
            int shortNum = min(height[begin], height[end]);
            int nowAreaSize = shortNum * (end - begin);
            maxAreaSize = nowAreaSize > maxAreaSize ? nowAreaSize : maxAreaSize;
            if(height[begin] < height[end])
            {
                begin++;
            }
            else
                end--;
        }
        return maxAreaSize;
        
    }
};