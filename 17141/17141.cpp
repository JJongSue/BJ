#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static int N;
static int M;
static vector<vector<int>> map;
static vector<pair<int,int>> okvirus;
static queue<pair<int, int>> virus_que;
static queue<pair<int, int>> empty_que;
static int ans;
const int dx[4] = {0, -1, 1, 0};
const int dy[4] = {-1, 0, 0, 1};
void select(int now, int cnt, queue<pair<int, int>> xy);
void virus_spread(queue<pair<int, int>> xy);
bool is_ok(int x, int y);
int main(void)
{
    //입력 map크기 N(0~50), 바이러스의 개수 M(1~10)
    //map 입력 0빈칸 1벽 2바이러스

    //N, M 입력 받음
    scanf("%d", &N);
    scanf("%d", &M);

    //map 지정
    map.assign(N, vector<int>(N, 0));
    okvirus.clear();
    //바이러스를 저장한 바이러스큐를 만들고 바이러스가 들어오면
    //바이러스 큐에 저장
    //바이러스 큐 clear
    virus_que = empty_que;
    ans = 10e8;
    //map입력 및 바이러스 큐 설정
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf(" %d", &map[i][j]);
            if (map[i][j] == 2)
            {
                okvirus.push_back(pair<int, int>(j, i));
                //virus_que.push(pair<int, int>(j, i));
                //printf("%d %d\n",i,j);
            }
        }
    }
    queue<pair<int, int>> vqc;
    select(0, 0, vqc);
    if (ans == 10e8)
        printf("-1\n");
    else
        printf("%d\n", ans);

    return 0;
}
//
void select(int now, int cnt, queue<pair<int, int>> xy)
{
    
    if (cnt == M)
    {
        //printf("%d %d %d %d\n", xy.front().first,xy.front().second,xy.back().first,xy.back().second);
        virus_spread(xy);
        return;
    }
    if (now >= okvirus.size())
        return;
    select(now + 1, cnt, xy);
    queue<pair<int, int>> copy =xy;
    copy.push(pair<int, int>(okvirus[now].first, okvirus[now].second));
    select(now + 1, cnt + 1, copy);
    /*if (map[okvirus[now].second][okvirus[now].first] == 2)
    {
        xy.push(pair<int, int>(now % N, now / N));
        select(now + 1, cnt + 1, xy);
    }*/
}
//바이러스 퍼짐
void virus_spread(queue<pair<int, int>> xy)
{
    queue<pair<int, int>> tmp_copy = xy;

    vector<vector<int>> map_copy = map;
    /*while (!xy.empty())
    {
        int x = xy.front().first;
        int y = xy.front().second;
        xy.pop();
        map_copy[y][x] = 2;
        tmp_copy.push(pair<int, int>(x, y));
    }*/
    int time = 0;
    while (!tmp_copy.empty())
    {
        
        if (time > ans)
            return;
        time++;
        queue<pair<int, int>> vq_copy = tmp_copy;
        tmp_copy=empty_que;
        while (!vq_copy.empty())
        {
            int x = vq_copy.front().first;
            int y = vq_copy.front().second;
            map_copy[y][x] =3;
            vq_copy.pop();
            tmp_copy.push(pair<int,int>(x,y));
        }
        vq_copy = tmp_copy;
        tmp_copy=empty_que;
        while (!vq_copy.empty())
        {
            int x = vq_copy.front().first;
            int y = vq_copy.front().second;
            map_copy[y][x] =3;
            vq_copy.pop();
            for (int i = 0; i < 4; i++)
            {
                if (is_ok(x + dx[i], y + dy[i]))
                {
                    if (map_copy[y + dy[i]][x + dx[i]] == 0 || map_copy[y + dy[i]][x + dx[i]] == 2)
                    {
                        map_copy[y + dy[i]][x + dx[i]] = 3;
                        tmp_copy.push(pair<int, int>(x + dx[i], y + dy[i]));
                    }
                }
            }
        }
        
    }
    time--;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map_copy[i][j] == 0 || map_copy[i][j] == 2)
                return;
        }
    }

    if (time < ans)
    {
        ans=time;
        /*if(time == 0) ans=1;
        else ans = time;*/
    }
        
}
//
bool is_ok(int x, int y)
{
    if (x < 0 || y < 0 || x >= N || y >= N)
        return false;
    return true;
}