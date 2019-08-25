#include <iostream>
#include <vector>
using namespace std;

const int dx[] = {0, 1};
const int dy[] = {
    1,
    0,
};

static vector<vector<int>> map;
static vector<vector<int>> ansvec;

static int N, M, ans;

int main()
{
    scanf("%d %d", &N, &M);

    map.assign(N, vector<int>(M, 0));
    ansvec.assign(N, vector<int>(M, 0));
    ans = N + M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf(" %d", &map[i][j]);
        }
    }
    if (N == 1 && M == 1)
    {
        printf("0\n");
    }
    else
    {
        for (int i = N - 1; i >= 0; i--)
        {
            for (int j = M - 1; j >= 0; j--)
            {
                if (i == N - 1 && j == M - 1)
                    continue;
                int min = N-1+M-1-i-j;
                for (int right = 1; right <= map[i][j]; right++)
                {
                    if (M - 1 < j + right)
                        break;
                    if (min > ansvec[i][j + right])
                        min = ansvec[i][j + right];
                }
                for (int under = 1; under <= map[i][j]; under++)
                {
                    if (N - 1 < i + under)
                        break;
                    if (min > ansvec[i + under][j])
                        min = ansvec[i + under][j];
                }
                ansvec[i][j] = min + 1;
            }
        }
        /*for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                printf("%d ", ansvec[i][j]);
            }
            printf("\n");
        }*/

        /*int item = map[0][0];
    map[0][0]=0;
    bfs(0,0,0,item);*/
        printf("%d\n", ansvec[0][0]);

        return 0;
    }
}
