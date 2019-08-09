#include <iostream>
#include <vector>
using namespace std;
int N, M, answer = 10e8;
vector<vector<int>> map;
vector<vector<int>> min_dis;
void dfs(int x, int y, int cnt);
int main(void)
{
    scanf("%d %d", &N, &M);
    map.assign(N, vector<int>(M, 0));
    min_dis.assign(N, vector<int>(M, -1));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }
    dfs(0, 0, 0);
    printf("%d", answer + 1);

    return 0;
}
void dfs(int x, int y, int cnt)
{
    if (x < 0 || y < 0 || x >= M || y >= N)
        return;
    if (map[y][x] == 0)
        return;
    if (cnt >= answer)
        return;
    if (y == N - 1 && x == M - 1)
    {
        if (cnt < answer)
        {
            min_dis[y][x] = cnt;
            answer = cnt;
        }
        return;
    }
    if (min_dis[y][x] != -1)
    {
        if (cnt < min_dis[y][x])
            min_dis[y][x] = cnt;
        else return;
    }

    min_dis[y][x] = cnt;
    dfs(x + 1, y, cnt + 1);
    dfs(x - 1, y, cnt + 1);
    dfs(x, y + 1, cnt + 1);
    dfs(x, y - 1, cnt + 1);
}