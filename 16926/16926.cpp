#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int N = 0, M = 0, R = 0;
    scanf("%d %d %d", &N, &M, &R);
    vector<vector<int>> map(N, vector<int>(M, 0));
    vector<vector<int>> copy_map(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            scanf(" %d", &map[i][j]);
    }
    copy_map=map;
    for (int j = 0; j < R; j++)
    {
        int a=0;
        copy_map=map;
       
        while (true)
        {
            //printf("%d\n", a);
            if (a >= N / 2 || a >= M / 2)
                break;
            for (int i = a + 1; i < N - a; i++)
            {
                map[i][a] = copy_map[i - 1][a];
            }
            for (int i = a + 1; i < M - a; i++)
            {
                map[N-1-a][i] = copy_map[N-1-a][i - 1];
            }
            for (int i = N - 1 - a; i > a; i--)
            {
                map[i - 1][M - 1 - a] = copy_map[i][M - 1 - a];
            }
            for (int i = M - 1 - a; i > a; i--)
            {
                map[a][i - 1] = copy_map[a][i];
            }
            a++;
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            printf("%d ", map[i][j]);
        }printf("\n");
    }

    return 0;
}