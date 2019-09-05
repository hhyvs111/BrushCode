#include <bits/stdc++.h>

using namespace std;

#define N 1000005

#define LL long long

LL a[N];
int n,m;
LL sum=0;

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    if(sum <= m){
        printf("%d\n",n+1);
        return 0;
    }
    LL res=0,used=0;
    int now=m,use=0;
    long long time=0;
    for(int i=0;i<n;i++){
        time++;
        if(a[i]<now){
            now += (use - a[i]);
            use = a[i]+use;
        }else{
            time++;
            a[i]-=now;
            now = m;
            time += a[i]/now;
            if(a[i] == 0){
                continue;
            }
            if(a[i]%now){
                time ++;
                now = now - a[i]%now;
                use = a[i]%now;
            }else {
                now = 0;
                use = m;
            }
        }
    }
    printf("%lld\n",time);
}