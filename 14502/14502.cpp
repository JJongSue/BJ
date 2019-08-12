#include <iostream>
#include <vector>
#include <queue>
using namespace std;
static int answer = -1;
static int N, M;
vector<vector<int>> copy_map;
void bfs(queue<pair<int, int>> b);
bool is_virus(int x, int y);
int main(void)
{
    // input N, N n*n의 map
    // 0 빈칸 1벽 2바이러스의 위치
    // 벽 3개를 세워서 바이러스가 퍼지지않는 최대의 안전지대

    // N, M 입력 N*M의 map 선언 및 입력
    scanf("%d %d", &N, &M);
    vector<vector<int>> map(N, vector<int>(M, 0));
    copy_map.assign(N, vector<int>(M, 0));
    queue<pair<int, int>> virus;
    queue<pair<int, int>> copy_virus;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf(" %d", &map[i][j]);
            if (map[i][j] == 2)
            {
                virus.push(pair<int, int>(j, i));
            }
        }
    }
    /*for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
            printf("%d ", map[i][j]);
        printf("\n");
    }*/
    for (int i = 0; i < (N * M)-2; i++)
    {
        int i_y = i / M;
        int i_x = i % M;
        if (map[i_y][i_x] != 0)
            continue;
        for (int j = i + 1; j < (N * M)-1; j++)
        {
            int j_y = j / M;
            int j_x = j % M;
            if (map[j_y][j_x] != 0)
                continue;
            for (int k = j + 1; k < N * M; k++)
            {
                int k_y = k / M;
                int k_x = k % M;
                if (map[k_y][k_x] != 0)
                    continue;
                //printf("%d %d \n%d %d \n%d %d\n\n\n", i_y, i_x, j_y, j_x, k_y, k_x);
                copy_map = map;
                copy_virus = virus;
                copy_map[i_y][i_x] = 1;
                copy_map[j_y][j_x] = 1;
                copy_map[k_y][k_x] = 1;
                bfs(copy_virus);
            }
        }
    }
    printf("%d\n", answer);

    return 0;
}
void bfs(queue<pair<int, int>> b)
{
    int cnt = 0;

    while (!b.empty())
    {
        cnt = 0;
        /*for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                //printf("%d ", copy_map[i][j]);
                if (copy_map[i][j] == 0)
                    cnt++;
            } //printf("\n");
        }*/
        //printf("\n\n");
        /*if (cnt < answer)
            return;*/
        int x = b.front().first;
        int y = b.front().second;
        b.pop();
        if (is_virus(x + 1, y))
        {
            copy_map[y][x + 1] = 2;
            b.push(pair<int, int>(x + 1, y));
        }
        if (is_virus(x - 1, y))
        {
            copy_map[y][x - 1] = 2;
            b.push(pair<int, int>(x - 1, y));
        }
        if (is_virus(x, y + 1))
        {
            copy_map[y + 1][x] = 2;
            b.push(pair<int, int>(x, y + 1));
        }
        if (is_virus(x, y - 1))
        {
            copy_map[y - 1][x] = 2;
            b.push(pair<int, int>(x, y - 1));
        }
    }
    cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            if (copy_map[i][j] == 0)
                cnt++;
    }
    if (cnt > answer)
    {
        answer = cnt;
        /*for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
                printf("%d ", copy_map[i][j]);
                    printf("\n");
            
        }printf("%d\n\n", cnt);*/
    }
    return;
}
bool is_virus(int x, int y)
{
    if (x < 0 || y < 0 || x >= M || y >= N)
        return false;
    if (copy_map[y][x] == 0)
        return true;
    return false;
}