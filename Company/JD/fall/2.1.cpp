#include <bits/stdc++.h>

using namespace std;

int a[5][5];

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int visit[5][5];
int c = 0;

void down(){

    for(int j = 0;j < 5;j++){
        stack<int>s;
        for(int i = 0;i < 5;i++){
            if(a[i][j]){
                s.push(a[i][j]);
            }
            a[i][j] = 0;
        }
        for(int i = 4;i >= 0 && !s.empty();i--){
            a[i][j] = s.top();
            s.pop();
        }
    }
}


void dfs(int x,int y,int r){
    c++;
    visit[x][y] = 1;
    for(int i = 0;i < 4;i++){
        int tx = x+dx[i];
        int ty = y+dy[i];
        if(a[tx][ty] == r){
            if(tx >= 0 && tx < 5 && ty >= 0 && ty < 5 && a[tx][ty] != 0 && visit[tx][ty] == 0)
                dfs(tx,ty,r);
        }
    }
    visit[x][y]=0;
}

void change(int x,int y,int r){
    a[x][y]=0;
    for(int i = 0;i < 4;i++){
        int tx = x+dx[i];
        int ty = y+dy[i];
        if(a[tx][ty] == r){
            if(tx >= 0 && tx < 5 && ty >= 0 && ty < 5 && a[tx][ty] != 0 && visit[tx][ty] == 0)
                change(tx,ty,r);
        }
    }
}


int main(){
    for(int i = 0;i < 5;i++){
        for(int j = 0;j < 5;j++){
            scanf("%d", &a[i][j]);
        }
    }
    while(1){
        int fall = 0;
        for(int i = 0;i < 5;i++){
            for(int j = 0;j < 5;j++){
                if(a[i][j]){
                    c = 0;
                    dfs(i, j, a[i][j]);
                    if(c > 2){
                        fall = 1;
                        change(i, j, a[i][j]);
                        down();
                    }
                }
            }
        }
        if(fall == 0){
            break;
        }
    }
    int res = 0;
    for(int i = 0;i < 5;i++){
        for(int j = 0;j < 5;j++){
            if(a[i][j])
                res++;
        }
    }
    printf("%d\n",res);
    return 0;
}