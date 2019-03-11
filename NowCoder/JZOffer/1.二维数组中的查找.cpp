
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int size = array.size();
        for(int i = 0;i < size;i++)
        {
            
            int size_m = array[i].size();
            if(target > array[i][size_m-])
                continue;
            else
            {
                for(int j = 0; j < size_m;j++)
                {
                    if(target == array[i][j])
                        return true;
                }
            }
        }
        return false;
    }
    
};

//这题为什么会断错误，有时间再看看