class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        //words是英文，判断这个英文是否是以order的顺序存储。
        //可以一个个遍历还是一起遍历？1
        //用order这个规则，来判断字典序
        //将这个order存入map，然后比较关键字，给order里的字母赋值12345
        unordered_map<char, int> orderMap;
        int cnt = 0;
        for(char i : order)
        {
            orderMap.insert({i,cnt++});
        }
        
        //逐个比较
        for(int i = 0; i < words.size() - 1;i++)
        {
            int sizeMin = min(words[i].size(), words[i+1].size());
            for(int j = 0;j < sizeMin;j++)
            {
                cout << orderMap[words[i][j]] << " " << orderMap[words[i+1][j]] << endl;
                if(orderMap[words[i][j]] > orderMap[words[i+1][j]])
                    return false;
                else if(orderMap[words[i][j]] < orderMap[words[i+1][j]])
                    break;
                //如果比较完了，1的长度更长，那么也是false
                if(j == sizeMin - 1 && sizeMin != words[i].size())
                    return false;
            }
        }
        return true;
        
         //别人的方法是把这个字母换成abc，然后看哪个大
    }
};