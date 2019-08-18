#include <iostream>
#include <vector>
#include <queue>
using namespace std;
static int N, M;
static vector<vector<int>> map;
static queue<pair<int, int>> que_empty;
static int dx[4] = {0, -1, 1, 0};
static int dy[4] = {-1, 0, 0, 1};
static int ans;
static vector<pair<int, int>> vxy;

bool is_ok(int x, int y);
void select(int now, int cnt, queue<pair<int, int>> p);
void spreadvirus(queue<pair<int, int>> p);
int main(void)
{
    //입력
    //N map의 크기, M 놓을 수 있는 바이러스의 수
    //N*N 맵 0빈칸 1벽 2바이러스를 놓을수 있는 공간
    //바이러스를 놓을 수없으면 -1출력
    //놓을 수있을때 최소시간
    scanf("%d %d", &N, &M);
    //queue<pair<int,int>> virus_que;
    map.assign(N, vector<int>(N, 0));
    vxy.clear();
    ans = 10e8;
    bool oneend = true;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf(" %d", &map[i][j]);
            if (map[i][j] == 0)
                oneend = false;
            if (map[i][j] == 2)
            {
                vxy.push_back(pair<int, int>(j, i));
            }
        }
    }
    if (oneend)
        printf("0\n");
    else
    {
        queue<pair<int, int>> p;
        select(0, 0, p);
        if (ans == 10e8)
            printf("-1\n");
        else
            printf("%d\n", ans);
    }

    return 0;
}
bool is_ok(int x, int y)
{
    if (x < 0 || y < 0 || x >= N || y >= N)
        return false;
    return true;
}
void select(int now, int cnt, queue<pair<int, int>> p)
{
    if (cnt == M)
    {
        spreadvirus(p);
        return;
    }
    if (now >= vxy.size())
    {
        return;
    }
    select(now + 1, cnt, p);
    p.push(pair<int, int>(vxy[now].first, vxy[now].second));
    select(now + 1, cnt + 1, p);
}

void spreadvirus(queue<pair<int, int>> p)
{

    vector<vector<int>> copy_map = map;
    queue<pair<int, int>> q_copy = p;
    int time = 0;

    int cnt =0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (copy_map[i][j] == 0)
            {
                cnt++;
            }
        }
    }
    if(cnt == 0) {
        ans = 0;
        return;
    }

    while (!q_copy.empty())
    {
        if(cnt == 0) break;
        time++;
        if (time > ans)
            return;

        queue<pair<int, int>> tmp = q_copy;
        q_copy = que_empty;
        while (!tmp.empty())
        {
            int x = tmp.front().first;
            int y = tmp.front().second;
            copy_map[y][x] = 3;
            tmp.pop();
            q_copy.push(pair<int, int>(x, y));
        }
        tmp = q_copy;
        q_copy = que_empty;
        while (!tmp.empty())
        {
            int x = tmp.front().first;
            int y = tmp.front().second;
            tmp.pop();
            for (int i = 0; i < 4; i++)
            {
                if (is_ok(x + dx[i], y + dy[i]))
                {
                    if (copy_map[y + dy[i]][x + dx[i]] == 0) cnt--;
                    if(copy_map[y + dy[i]][x + dx[i]] == 0 || copy_map[y + dy[i]][x + dx[i]] == 2)
                    {
                        copy_map[y + dy[i]][x + dx[i]] = 3;
                        q_copy.push(pair<int, int>(x + dx[i], y + dy[i]));
                    }
                }
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (copy_map[i][j] == 0)
                return;
        }
    }
    if (ans > time)
    {
        if (time == -1)
            time = 0;
        ans = time;
    }
}