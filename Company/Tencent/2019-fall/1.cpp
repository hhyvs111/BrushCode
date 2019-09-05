#include <bits/stdc++.h>

using namespace std;

vector<long> vec;
vector<long> vec1;

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<n;i++)
    {
        long temp;
        scanf("%d", &temp);
        vec.push_back(temp);
    }
    for(int i = 0;i<m;i++)
    {
        long temp;
        scanf("%d", &temp);
        vec1.push_back(temp);
    }

    int count = 0;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            if(vec1[j] == 0)
            {
                continue;
            }
            else if(vec1[j]!=0)
            {
                if((vec[i]+vec1[j])%2!=0)
                {
                    vec1[j] = 0;
                    count++;
                    break;
                }
            }
        }
    }
    cout<<count<<endl;

    return 0;

}