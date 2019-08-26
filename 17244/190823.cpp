#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int dx[] = {0, -1, 1, 0};
const int dy[] = {-1, 0, 0, 1};
static vector<vector<char>> map;
static vector<vector<bool>> is_visitmap;
static vector<bool> is_visit;
static vector<vector<int>> dis;
static vector<vector<int>> dis_map;
static vector<pair<int, int>> pro;
static queue<pair<int, int>> mainque;
static queue<pair<int, int>> emptyque;

static int N, M, num, answer;
static int sx, sy, ex, ey;
void find_ans(int num, int ans, int post);
bool is_map(int x, int y);
//void bfs(int x, int y, int now, int cnt, int distan);
void bfs();
int main(void)
{
    scanf("%d %d", &M, &N);
    map.assign(N, vector<char>(M, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf(" %c", &map[i][j]);
            if (map[i][j] == 'S')
            {
                sx = j;
                sy = i;
            }
            else if (map[i][j] == 'X')
            {
                pro.push_back(pair<int, int>(j, i));
            }
            else if (map[i][j] == 'E')
            {
                ex = j;
                ey = i;
            }
        }
    }
    //printf("%c\n", map[sy][sx]);
    num = pro.size() + 2;
    dis.assign(num, vector<int>(num, -1));
    dis_map.assign(N, vector<int>(M, -1));
    mainque = emptyque;
    dis_map[sy][sx]=0;
    mainque.push(pair<int, int>(sx, sy));
    bfs();
  
    for (int i = 0; i < pro.size(); i++)
    {
        int x = pro[i].first;
        int y = pro[i].second;
        dis[i + 1][0] = dis_map[y][x];
        dis[0][i + 1] = dis_map[y][x];
    }
    dis[num-1][0] = dis_map[ey][ex];
    dis[0][num-1] = dis_map[ey][ex];

    for (int j = 1; j < num - 1; j++)
    {
        dis_map.assign(N, vector<int>(M, -1));
        mainque = emptyque;
        int x = pro[j-1].first;
        int y = pro[j-1].second;
        dis_map[y][x]=0;
        mainque.push(pair<int, int>(x, y));
        bfs();
        for (int i = 0; i < pro.size(); i++)
        {
            x = pro[i].first;
            y = pro[i].second;
            dis[i + 1][j] = dis_map[y][x];
            dis[j][i + 1] = dis_map[y][x];
        }
        dis[num-1][j] = dis_map[ey][ex];
        dis[j][num-1] = dis_map[ey][ex];
    }
    /*for(int i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
        {
            printf("%d ", dis[i][j]);
        }printf("\n");
    }*/
    /*is_visitmap.assign(N, vector<bool>(M,false));
    is_visitmap[sy][sx]=true;
    bfs(sx,sy,0,0,0);

    is_visitmap.assign(N, vector<bool>(M,false));
    is_visitmap[ey][ex]=true;
    bfs(ex,ey,0,0,num-1);
    
    for(int i=0;i<pro.size();i++)
    {
        int cnt=0;
        is_visitmap.assign(N, vector<bool>(M,false));
        is_visitmap[pro[i].second][pro[i].first]=true;
        for(int j=0;j<dis.size();i++)
        {
            if(dis[i+1][j]!=-1) cnt++;
        }
        bfs(pro[i].first, pro[i].second, i+1, cnt, 0);
        
    }
    for(int i=0;i<dis.size();i++)
    {
        for(int j=0;j<dis.size();j++)
        {
            printf("%d ", dis[i][j]);
        }printf("\n");
    }*/
    answer = 10e8;
    is_visit.assign(num, false);
    find_ans(0, 1, 0);
    printf("%d\n", answer);
    return 0;
}

void bfs()
{
    int distan = 1;
    while (!mainque.empty())
    {
        queue<pair<int, int>> tmpque = mainque;
        mainque = emptyque;
        while (!tmpque.empty())
        {
            
            int x = tmpque.front().first;
            int y = tmpque.front().second;
            
            tmpque.pop();
            for (int i = 0; i < 4; i++)
            {
                if (is_map(x + dx[i], y + dy[i]))
                {
                    
                    dis_map[y+dy[i]][x+dx[i]] = distan;
                    mainque.push(pair<int, int>(x + dx[i], y + dy[i]));
                }
            }
        }
        distan++;
    }
}

/*void bfs(int x, int y, int now, int cnt, int distan)
{
    printf("%d %d\n", x, y);
    if (cnt == num)
        return;
    if (x == sx && y == sy && dis[0][now] == -1)
    {
        cnt++;
        dis[0][now] = distan;
        dis[now][0] = distan;
    }
    if (x == ex && y == ey && dis[num - 1][now] == -1)
    {
        cnt++;
        dis[num - 1][now] = distan;
        dis[now][num - 1] = distan;
    }

    for (int i = 0; i < pro.size(); i++)
    {
        if (x == pro[i].first && y == pro[i].second && dis[i + 1][now] == -1)
        {
            cnt++;
            dis[i + 1][now] = distan;
            dis[now][i + 1] = distan;
            break;
        }
    }
    if (cnt == num)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (is_map(x + dx[i], y + dy[i]))
        {
            is_visitmap[y + dy[i]][x + dx[i]] = true;
            bfs(x + dx[i], y + dy[i], now, cnt, distan + 1);
        }
    }
}*/
bool is_map(int x, int y)
{
    if (x < 0 || y < 0 || x >= M || y >= N)
        return false;
    if (map[y][x] == '#')
        return false;
    if (dis_map[y][x] != -1)
        return false;
    return true;
}
void find_ans(int now, int ans, int post)
{
    if (ans >= answer)
        return;
    if (now == num-1)
    {
        //printf("\n");
        if (answer > ans + dis[post][num - 1])
            answer = ans + dis[post][num - 1];
        return;
    }
    for (int i = 1; i < num; i++)
    {
        if (!is_visit[i])
        {
            //printf("#%d %d %d %d\n", now, post, num, ans);
            is_visit[i] = true;
            find_ans(now + 1, ans + dis[post][i], i);
            is_visit[i] = false;
        }
    }
}