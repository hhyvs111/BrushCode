class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int size = A.size();
        
        map<int,int> intMap;
        for(int i : A)
        {
            if(!intMap.insert({i,1}).second)
            {
                intMap[i]++;
                cout << intMap[i] << endl;
                if(intMap[i] == size/2)
                    return i;
            }
        }
        return 0;
    }
};