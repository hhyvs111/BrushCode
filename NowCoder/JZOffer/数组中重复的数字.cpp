class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        for(int i = 0 ;i < length;i++)
        {
            //将这个值放到对应的位置，比如2在数组的4号位，那么将其和数组2号位的数字交换。
            if(numbers[i] != i)
            {
                //如果又出现不对应的事情，那么判断是否原本位置是否已经正确摆放了，如果已经正确摆放了的话
                //代表这个数就是重复的数字。输出它
                if(numbers[numbers[i]] == numbers[i])
                {
                    *duplication = numbers[i];
                    return true;
                }
                swap(numbers[i], numbers[numbers[i]]);
            }
        }
        return false; 
    }
};