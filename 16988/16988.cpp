#include <iostream>
#include <vector>
using namespace std;
static int N, M, ans = 0;
vector<vector<int>> map;
int main(void)
{
    //행렬 N, M
    //0빈칸 1나의돌 2상대돌
    //돌 2개로 죽일 수 있는 상대 돌의 최대 갯수
    scanf("%d %d", &N, &M);
    map.assign(N+2,vector<int>(M+2,1));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            scanf(" %d", &map[i+1][j+1]);
        }
    }
    for(int i=1;i<N*M;i++)
    {
        if(map[i/N][i%M] != 0) continue;
        for(int j=i+1;j<=N*M;j++)
        {
            if(map[j/N][j%M] != 0) break;
            map[i/N][i%M] = 1;
            map[j/N][j%M] = 1;
        }
    }

}