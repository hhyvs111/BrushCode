class Solution {
public:
    //看看大佬的代码吧。好像我处理的有点复杂了，可以将两个合并，只要出现过一次的就是有误的。
    //那我之前写那么多，真的是sb了！直接都放入一个map就好了。
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> count;
        istringstream iss(A + " " + B);
        while (iss >> A) count[A]++;
        vector<string> res;
        for (auto w: count)
            if (w.second == 1)
                res.push_back(w.first);
        return res;
    }
    vector<string> uncommonFromSentences(string A, string B) {
        //设置一个set，然后对比，看值不一样的地方
        //如果有一个词在同一句出现两次，那么也是可以的，那么不能用这个set了，要用map了
        map<string, int> wordsA;
        map<string, int> wordsB;
        vector<string> ans;
        int sizeA = A.size(), sizeB = B.size();
        int begin = 0;
        for(int i = 0;i < sizeA;i++)
        {
            if(A[i] == ' ' )
            {
                cout << "A " << A.substr(begin, i - begin) << endl;
                if(!wordsA.insert({(A.substr(begin, i - begin)), 0}).second)
                {
                    wordsA[(A.substr(begin, i - begin))]++;
                }
                begin = i+1;
            }
        }
        //把最后一个字符串入
        if(!wordsA.insert({(A.substr(begin, sizeA - begin)), 0}).second)
        {
            wordsA[(A.substr(begin, sizeA - begin))]++;
        }
        // wordsA.insert(A.substr(begin, sizeA - begin));
        begin = 0;
        for(int i = 0;i < sizeB;i++)
        {
            if(B[i] == ' ')
            {
                 cout << "B " << B.substr(begin, i - begin) << endl;
                if(!wordsA.insert({(B.substr(begin, i - begin)), 0}).second)
                {
                    wordsA[(B.substr(begin, i - begin))]++;
                }
                begin = i+1;
            }
        }
        if(!wordsA.insert({(B.substr(begin, sizeB - begin)), 0}).second)
        {
            wordsA[(B.substr(begin, sizeB - begin))]++;
        }
        //此时的string是排序的，那么依次遍历对比
//         int sizeOfSetA = wordsA.size();
//         int sizeOfSetB = wordsB.size();
//         cout << sizeOfSetA << sizeOfSetB << endl;
//         int minSize = min(sizeOfSetA, sizeOfSetB);
//         int j = 0;
        
//         auto itB = wordsB.begin();
//         //不能逐个比较，只能代入比较了，找不到的之间加入ans，要排除这个i>=2的值，然后已经加入ans的置为-1
//         for(;itB != wordsB.end();itB++)
//         {
//             if(itB->second >= 1)
//             {
//                 //如果找到了
//                 if(wordsA.find(itB->first) != wordsA.end())
//                     wordsA[itB->first]++;
//             }
//             else
//             {
//                 //如果存在这个值，那么加1
//                 // //全部都插入到A，如果这个值不在A里
//                 if(!wordsA.insert({itB->first,0}).second)
//                 {
//                     cout << itB->first << " go" << endl;
//                     wordsA[itB->first]++;
//                 }
//                 else
//                     cout << itB->first << " no go" << endl;
//             }
//         }
        //现在遍历A
        //把迭代器放在这，之前放在b的前面，导致更新后迭代器还是老的迭代器
        for(auto itA = wordsA.begin();itA != wordsA.end();itA++)
        {
            if(itA->second == 0 )
            {
                cout << "ans " << itA->first << endl;
                ans.push_back(itA->first);
            }
                
        }
        // while(j++ < minSize)
        // {
        //     if(())
        //     cout << itA->first << " " << itB->first <<endl;
        //     if(itA->first != itB->first)
        //     {
        //         if(itA->second != 0 && itB->second == 0)
        //             ans.push_back(itB->first);
        //         else if(itA->second == 0 && itB->second != 0)
        //             ans.push_back(itA->first);
        //         else if(itA->second == 0 && itB->second == 0)
        //         {
        //             ans.push_back(itA->first);
        //             ans.push_back(itB->first);
        //         }
        //     }
        //     itA++;
        //     itB++;
        // }
        // if(sizeOfSetA > sizeOfSetB)
        // {
        //     while(j++ < sizeOfSetA)
        //     {
        //         if(itA->second == 0)
        //             ans.push_back(itA->first);
        //         itA++;
        //     }
        // }
        // else
        // {
        //     while(j++ < sizeOfSetB)
        //     {
        //         if(itB->second == 0)
        //             ans.push_back(itB->first);
        //         itB++;
        //     }
        // }
        return ans;
    }
};