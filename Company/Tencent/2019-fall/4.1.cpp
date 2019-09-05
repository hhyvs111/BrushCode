#include<bits/stdc++.h>
using namespace std;
const int Maxn = 5e5+10;
int a[Maxn];

 
int main(){


  
    while(scanf("%d",&n) == 1){
  
  for(int i = 1; i <= n; i++)
  {
   scanf("%d",&a[i]);
  }
  
  int Max1 = 0;
  for(int i = 1; i <= n; i++){
   int Min1 = a[i];
   int sum = a[i];
   for(int j = i-1; j >=1; j--){
    if(a[j] >= Min1)  sum += a[j];
    else break;
   }
   
   for(int j = i+1; j <=n; j++){
    if(a[j] >= Min1)  sum += a[j];
    else break;    
   }
   Max1 = max(Max1,sum * Min1);
  }
  
  printf("%d\n",Max1);
 } 
 return 0;

}