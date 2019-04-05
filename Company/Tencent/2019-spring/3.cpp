#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> monster(n);
    vector<int> money(n);
    for(int i = 0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        monster[i] = tmp;
    }
    for(int i = 0;i<n;i++)
    {
        int t;
        cin>>t;
        money[i] = t;
    }
    int indexMonster = monster[0];
    int indexMoney = money[0];
    for(int i = 1;i < n;i++)
    {
        for(int j = i+ 1;j < n;j++)
        {
              if(indexMonster <= monster[j])
              {
                    indexMoney += money[i];
                    indexMonster += monster[i];
              }
        }
    }
    cout << indexMoney << endl;
    return 0;
}