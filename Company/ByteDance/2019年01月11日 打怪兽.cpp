#include<iostream>
#include<algorithm>
using namespace std;
#define max 100000

bool cmp(int a,int b)
{
    return a > b;
}
int main()
    
{
    int N, a, b;
    
    int m[max];
    //怪兽的血量
    while(cin >> N >> a >> b)
    {
        for(int i = 0;i < N;i++)
            cin>>m[i];
        int count = 0;
        sort(m,m+N,cmp);
        //排个序
        int num = 0;
        while(N)
        {
              //主要攻击
               if(m[num] > 0)
               {
                   m[num] -= a;
                   count++;
                   for(int j = (num + 1);j < N;j++)
                   {
                       if( m[j] > 0)
                       {
                           m[j] -= b;
                           if(m[j] <= 0)
                               N--;
                       }
                   }
                   if(m[num] <= 0)
                   {
                       //攻击下一个
                       N--;
                       num++;
                   }
                }
        }
        cout << count <<endl;
    }
    return 0;
}