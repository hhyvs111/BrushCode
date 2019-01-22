class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
//         map<int,int> Map;
//         //用map，统计每个数有多少个
//         for(int i = 0;i < deck.size();i++)
//             if(Map.find(deck[i])) 
//                 Map[deck[i]]++;
//             else
//                 Map.insert(deck[i]);
            
//         for(auto i : Map)
//             //如果有这
//             if(i.second % 2) return false;
        unordered_map<int, int> count;
        int res = 0;
        for (int i : deck) count[i]++;
        for (auto i : count) res = __gcd(i.second, res);
        return res > 1;
        //最大公约数，真的牛批
    }
};

//这题用到了最大公约数，有点意思。