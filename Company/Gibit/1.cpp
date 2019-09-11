#include<bits/stdc++.h>
using namespace std;
int main() {
    string str1, str2;
    cin >> str1 >> str2;
    int maxIndex = -1;
    for(int i = 0;i < str1.size();i++) {
        if(str1[i] == str2[0]) {
            int j = i + 1;
            int k = 1;
            while(j < str1.size() && k < str2.size()) {
                if(str1[j] == str2[k]) {
                    k++;
                }
                j++;
            }
            // cout << i << " " << endl;
            if(k == str2.size())
                maxIndex = i;
        }
    }
    if(maxIndex == -1) 
        cout << 0 << endl;
    else
        cout << maxIndex + 1 << endl;
    return 0;

}