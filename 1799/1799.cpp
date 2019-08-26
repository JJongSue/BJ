#include<iostream>
#include<vector>
using namespace std;
static vector<vector<int>> map;

static int N, ans = 0;
void go_map(int now, int cnt);
int main()
{
    scanf("%d", &N);
    map.assign(N, vector<int>(N, 0));
    int max = 0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf(" %d", &map[i][j]);
            
        }
    }
    for(int j=0;j<N;j++)
    {
        int ur =0, ul = 0, dl=0, dr=0;
        for(int i=0;i<N;i++)
        {
            if(j+i<N && map[i][j]==1){
                ur++;
            }
            if(j-1>=0 && map[i][j]==1){
                ul++;
            }
            if(j+i<N && map[N-1+i][j]==1){
                dr++;
            }
            if(j-1>=0 && map[i][j]==1){
                dl++;
            }
        }
    }
    
    go_map(0,0);
    printf("%d\n", ans);

}
void go_map(int now, int cnt)
{
    printf("%d\n", now);
    if(cnt == 10)
    {
        ans = 10;
        return;
    }
    if(now == N*N-1)
    {
        if(map[N-1][N-1]==1)
        {
            if(ans < cnt+1) ans=cnt+1;
        }
        else{
            if(ans < cnt) ans = cnt;
        }
        return;
    }
    if(map[now/N][now%N])
    {
        
        vector<vector<bool>> copy_map =map;
        for(int i=now/N+1;i<N;i++)
        {
            if(now%N+(i-now/N) < N) map[i][now%N+(i-now/N)]=false;
            if(now%N-(i-now/N) >= 0) map[i][now%N-(i-now/N)]=false;
        }
        go_map(now+1, cnt+1);
        map=copy_map;
        go_map(now+1, cnt);
        return;
    }
    else{
        go_map(now+1, cnt);
        return;
    }
}