#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int dx[] = {0, -1, 1, 0};
const int dy[] = {-1, 0, 0, 1};

static int M, N;
static vector<vector<char>> map;
static vector<bool> is_visit;
static vector<vector<int>> dis;
static vector<vector<int>> dis_map;
static vector<pair<int, int>> dirty;
static int ans;
static int s_x, s_y;
void select_num(int now, int cnt, int sum);

bool is_go(int x, int y);
int main(void)
{
    while (true)
    {
        scanf("%d %d", &M, &N);
        if (N == 0 && M == 0)
            break;
        map.assign(N, vector<char>(M, '.'));
        dis_map.assign(N, vector<int>(M, -1));
        ans = 10e8;
        dirty.clear();
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                scanf(" %1c", &map[i][j]);
                if (map[i][j] == '*')
                    dirty.push_back(pair<int, int>(j, i));
                if (map[i][j] == 'o')
                {
                    s_x = j;
                    s_y = i;
                }
            }
        }
        int cnt = 1;
        queue<pair<int, int>> mq;
        mq.push(pair<int, int>(s_x, s_y));
        dis_map[s_y][s_x] = 0;
        while (!mq.empty())
        {
            queue<pair<int, int>> subq;
            while (!mq.empty())
            {
                int x = mq.front().first;
                int y = mq.front().second;
                mq.pop();
                for (int i = 0; i < 4; i++)
                {
                    if (is_go(x + dx[i], y + dy[i]))
                    {
                        subq.push(pair<int, int>(x + dx[i], y + dy[i]));
                        dis_map[dy[i] + y][dx[i] + x] = cnt;
                    }
                }
            }
            cnt++;
            mq = subq;
        }
        dis.assign(dirty.size() + 1, vector<int>(dirty.size() + 1, 0));
        for (int i = 0; i < dirty.size(); i++)
        {
            dis[0][i + 1] = dis_map[dirty[i].second][dirty[i].first];
            dis[i + 1][0] = dis_map[dirty[i].second][dirty[i].first];
        }
        for (int i = 0; i < dirty.size(); i++)
        {
            int cnt = 1;
            dis_map.assign(N, vector<int>(M, -1));
            mq.push(pair<int, int>(dirty[i].first, dirty[i].second));
            dis_map[dirty[i].second][dirty[i].first] = 0;
            while (!mq.empty())
            {
                queue<pair<int, int>> subq;
                while (!mq.empty())
                {
                    int x = mq.front().first;
                    int y = mq.front().second;
                    mq.pop();
                    for (int i = 0; i < 4; i++)
                    {
                        if (is_go(x + dx[i], y + dy[i]))
                        {
                            subq.push(pair<int, int>(x + dx[i], y + dy[i]));
                            dis_map[dy[i] + y][dx[i] + x] = cnt;
                        }
                    }
                }
                cnt++;
                mq = subq;
            }
            for (int j = 0; j < dirty.size(); j++)
            {
                dis[i + 1][j + 1] = dis_map[dirty[j].second][dirty[j].first];
                dis[j + 1][i + 1] = dis_map[dirty[j].second][dirty[j].first];
            }
        }

        /*for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                printf("%2d ", dis_map[i][j]);
            }
            printf("\n");
        }*/

        /*for (int i = 0; i < dis.size(); i++)
        {
            for (int j = 0; j < dis.size(); j++)
            {
                printf("%2d ", dis[i][j]);
            }
            printf("\n");
        }*/
        bool is_minus = false;
        for (int i = 0; i < dis.size(); i++)
        {
            if (is_minus)
                break;
            for (int j = 0; j < dis.size(); j++)
            {
                if (dis[i][j] == -1)
                {
                    is_minus = true;
                    break;
                }
            }
        }
        if (is_minus)
            printf("-1\n");
        else
        {
            is_visit.assign(dis.size(), false);
            select_num(0, 0, 0);
            printf("%d\n", ans);
        }
    }

    return 0;
}
bool is_go(int x, int y)
{
    if (x < 0 || y < 0 || x >= M || y >= N)
        return false;
    if (dis_map[y][x] != -1)
        return false;
    if (map[y][x] == 'x')
        return false;
    return true;
}
void select_num(int now, int cnt, int sum)
{
    if (ans < sum)
        return;
    if (cnt == dis.size()-1)
    {
        ans = sum;
        return;
    }
    for (int i = 1; i < dis.size(); i++)
    {
        if (!is_visit[i])
        {
            is_visit[i] = true;
            select_num(i, cnt + 1, sum + dis_map[now][i]);
            is_visit[i] = false;
        }
    }
}