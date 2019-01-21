class Solution {
public:
    int maxDistToClosest(vector<int> seats) {
        int i, j, res = 0, n = seats.size();
        for (i = j = 0; j < n; ++j)
            if (seats[j] == 1) {
                //当第一次出现1的时候，计算左边界
                if (i == 0) res = max(res, j - i);
                //当中间出现1的时候，将当前位置减去上一次出现0的位置，然后除以2就是距离
                else res = max(res, (j - i + 1) / 2);
                i = j + 1;
            }
            //最后计算一下右边界，
        res = max(res, n - i);
       return res;
        }     
    };
//         //在一堆位置里找到连续最多的空位，然后坐在中间
//         //统计连续的0有多少个
        
//         int maxSumZero = 0, nowSumZero = 0;
//         //上一次0的位置
//         int LastZero = 0;
//         int zeroBegin= 0, zeroEnd = 0;
//         for(int i = 0;i < seats.size();i++)
//         {
//             if(seats[i] == 0)
//             {
//                 if(nowSumZero == 0)
//                     LastZero = i;
//                 nowSumZero++;
//             }
//             else
//             {
//                 nowSumZero = 0;
//             }
//             if(nowSumZero > maxSumZero)
//             {
//                 if(maxSumZero != 0 && maxSumZero - nowSumZero == -1)
//                 {
//                     if(zeroBegin == 0)
//                         continue;
//                 }
//                 maxSumZero = nowSumZero;
//                 zeroBegin = LastZero;
//                 zeroEnd = i;
//             }
//             //考虑在边界的情况
//             else if(nowSumZero == maxSumZero && i == seats.size() - 1)
//             {
//                 zeroBegin = LastZero;
//                 zeroEnd = i;
//             }
//         }
//         // cout << zeroBegin << " "<< zeroEnd << " "<< maxSumZero<<endl;
//         if(zeroBegin == 0 || zeroEnd == seats.size() - 1)
//             return maxSumZero;
//         else
//             return (maxSumZero + 1)/2;
            
//     }
