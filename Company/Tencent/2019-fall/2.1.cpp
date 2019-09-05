#include <bits/stdc++.h>
using namespace std;

#define LL long long
struct Node{
    LL a;
    LL b;
    bool operator<(const Node& x){
        return a-b < x.a-x.b;
    }
}t[100005];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld %lld",&t[i].a,&t[i].b);
    }
    LL res=0;
    sort(t,t+n);
    for(int i=0;i<n;i++){
        int p = n-i;
        res += t[i].a*(p-1)+t[i].b*(n-p);
    }
    printf("%lld\n",res);
}