#include<bits/stdc++.h>
using namespace std;
int main()
{
    unordered_set<string> strMap;
    string a, b;
    while(cin >> a >> b){
        int sizeA = a.size();
        int sizeB = b.size();
        for(int i = 0;i < sizeA - sizeB + 1;i++)
        {
            if(a[i] == b[0] || b[0] == '?'){
                int cnt = 0;
                for(int j = 0;j < sizeB;j++){
                    if(a[i + j] == b[j] || b[j] == '?')
                        cnt++;
                    else
                        break;
                }
                if(cnt == sizeB){
                    strMap.insert(a.substr(i, sizeB));
                }
            }
        }
        cout << strMap.size() << endl;
    }
    return 0;
}