#include <iostream>
#include <vector>
using namespace std;
static int N, M, ans = 0, cnt;
static vector<vector<int>> map;
static vector<vector<int>> copy_map;
static bool is_count;
bool is_map(int x, int y);
void count_bd(int x, int y);
int main(void)
{
    //행렬 N, M
    //0빈칸 1나의돌 2상대돌
    //돌 2개로 죽일 수 있는 상대 돌의 최대 갯수
    scanf("%d %d", &N, &M);
    map.assign(N+1,vector<int>(M+1,1));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            scanf(" %d", &map[i][j]);
        }
    }

    for(int i=0;i<N*M;i++)
    {
        int s = M;//M>N ? M : N;
        if(map[i/s][i%s] != 0) continue;
        for(int j=i+1;j<N*M;j++)
        {
            if(map[j/s][j%s] != 0) continue;
            copy_map.clear();            
            copy_map=map;
            copy_map[i/s][i%s] = 1;
            copy_map[j/s][j%s] = 1;
            int anstmp=0;
            /*for(int cpmi=0;cpmi<N;cpmi++)
            {
                for(int cpmj=0;cpmj<M;cpmj++)
                {
                    printf("%d ", copy_map[cpmi][cpmj]);
                }printf("\n");
            }printf("\n\n");*/

            for(int fi=0;fi<N;fi++)
            {
                for(int fj=0;fj<M;fj++)
                {
                    if(copy_map[fi][fj]==2)
                    {
                        is_count=true;
                        cnt=0;
                        count_bd(fj,fi);
                        if(is_count)
                        {
                            anstmp+=cnt;
                        }
                    }
                }
            }//if(anstmp!=0) printf("%d", anstmp);
            if(ans < anstmp) {ans=anstmp; }
        }
    }
    printf("%d\n", ans);
    return 0;
}

void count_bd(int x, int y)
{
    if(!is_map(x,y)) return;
    if(copy_map[y][x] == 2){
        copy_map[y][x] = -1;
        cnt++;
        count_bd(x+1,y);
        count_bd(x-1,y);
        count_bd(x,y+1);
        count_bd(x,y-1);
        return;
    }
    if(copy_map[y][x] == 0)
    {
        is_count=false;
    }
    return;

}
bool is_map(int x, int y)
{
    if(x < 0 || y < 0 || x >= M || y>=N) return false;
    return true;
}