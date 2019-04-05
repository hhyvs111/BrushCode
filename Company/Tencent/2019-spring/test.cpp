#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n; //n种不同面值的硬币
   int m;
   int i , j ,k;
   cout<<"请输入有几种不同的面值:";
   cin>>n;
   int *t =new int[n+1];               //硬币的面值存放在t数组中 -- 价值
   int *coin = new int [n+1];      //可以使用的硬币个数存放在coin中--个数
   cout<<"请输入"<<n<<"组硬币的面值和对应的个数（中间用空格隔开）:"<<endl;
   for(i = 1 ;i<n+1;i++)
       cin>>t[i]>>coin[i];
   cout<<"请输入要找的钱数m:";
   cin>>m;
   int dp[20002]={0} ;   //dp[i] 用来记录钱数为i时的最少的硬币数
   for(i=1;i<=m;i++)
       dp[i] = 99999;
   //dp[0] = 0;
   int maxCoin = 0;
   for(i = 1 ;i <= n ; i++)    //硬币面值的种数
       for(j = 1 ; j <= coin[i] ; j++)   //硬币的面值的个数
           for( k = m ; k >= t[i] ;  k-- )    
           {

               dp[k] = min(dp[k-t[i]] +1,dp[k]);
               if(dp[k] != 99999)
                  maxCoin = max(dp[k], maxCoin);
               //cout<<k<<": "<<dp[k]<<endl;  用于测试使用
           }
   cout<<"最少需要用到的硬币个数是:";
   if(dp[m] == 99999)cout<<-1<<endl;
   else cout<<dp[m]<<"个"<<endl;

   cout << maxCoin << endl;
}

