class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        //就是看是否有间隔
        int size = flowerbed.size();
        int cnt = 0;
        int i = 0;
        while(i < size)
        {
            //如果这个位置是0，那么有满足三个条件则可以种植
            //如果当前是边界（i==0）那么只要满足i+1都值为0，依此类推
            if(flowerbed[i] == 0 && ( i == 0 || flowerbed[i-1] ==0) && (i == size-1 || flowerbed[i+1] == 0))
            //巧妙的利用了条件类比，但是不会出现越界的情况？好像不会，如果前面的满足了，那么就不会判定后面的，牛批
            {
                cnt++;
                flowerbed[i] = 1;
            }
            i++;
        }
        return cnt >= n;
//         for(int i = 1;i < flowerbed.size() - 1;i++)
//         {
//             //开头可以中一株
//             if(i == 1 && flowerbed[i] == 0 && flowerbed[i-1] == 0)
//             {
//                 cout << n <<endl;
//                 n--;
//                 flowerbed[i-1] = 1;
//             }
//             if(flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0)
//             {
//                 n--;
//                 flowerbed[i] = 1;
//             }
                
//             if(i == size - 2 && flowerbed[i] == 0 && flowerbed[i+1] == 0)
//             {
//                 cout << n <<endl;
//                 n--;
//             }
//         }
//         if(n < 1)
//             return true;
//         return false;
    }
};