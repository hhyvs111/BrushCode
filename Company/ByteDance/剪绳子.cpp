#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin >> n >> m;
    vector<int> len;
    int temp;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        len.push_back(temp);
    }
    sort(len.begin(),len.end());
    double last;
    if(m%2) last = len[]
     = (double)(len[0] + len[1])/2;
    cout << last << endl;
    return 0;
}