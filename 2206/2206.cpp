#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
const int dx[4] = {0,-1,1,0};
const int dy[4] = {-1,0,0,1};
#define p = pair<int,int>
using namespace std;

static int ans;
static vector<vector<int>> map;
static vector<vector<bool>> is_visit;
static vector<vector<bool>> is_visit2;
static int N, M;
void bfs(int x, int y, int now, bool is_remove);
bool is_map(int x, int y);
int main(void)
{
    scanf("%d %d", &N, &M);
    map.assign(N, vector<int>(M, 0));
    is_visit.assign(N, vector<bool>(M, false));
    is_visit2.assign(N, vector<bool>(M, false));
    queue<pair<pair<int,int>,bool>> wall;
    ans = N * M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%1d", &map[i][j]);
            /*if (map[i][j] == 1)
                wall.push(pair<int, int>(j, i));*/
        }
    }
    //int tmp[3] = {0,0,0};
    wall.push(pair<pair<int,int>,bool>(pair<int,int>(0,0), false));
    int cnt =0;
    int ans = -1;
    queue<pair<pair<int,int>,bool>> q_empty;
    is_visit[0][0]= true;
    is_visit2[0][0]= true;
    while(!wall.empty())
    {        
        if(is_visit[N-1][M-1] || is_visit2[N-1][M-1]){
            ans=cnt;
            break;
        }
        queue<pair<pair<int,int>,bool>> inq = wall;
        wall = q_empty;
        while(!inq.empty())
        {
            
            pair<pair<int,int>,bool> tmp = inq.front();
            inq.pop();            
            int x = tmp.first.first;
            int y = tmp.first.second;
            bool is_use = tmp.second;
            //printf("%d %d\n",x,y);
            //if(is_visit[y][x]) continue;
            is_visit[y][x]=true;            
            for(int i=0;i<4;i++)
            {
                if(is_map(x+dx[i],y+dy[i]))
                {
                    if(is_visit[y+dy[i]][x+dx[i]]) continue;
                    if(map[y+dy[i]][x+dx[i]] == 1)
                    {
                        if(is_visit2[y+dy[i]][x+dx[i]]) continue;
                        if(is_use) continue;
                        else{
                            is_visit[y+dy[i]][x+dx[i]]=true;
                            is_visit2[y+dy[i]][x+dx[i]]=true;
                            wall.push(pair<pair<int,int>,bool>(pair<int,int>(x+dx[i],y+dy[i]),true));
                        }
                    }
                    else{
                        if(!is_use)
                        {
                            is_visit2[y+dy[i]][x+dx[i]]=true;
                            is_visit[y+dy[i]][x+dx[i]]=true;
                        }
                        if(y+dy[i]==N-1 && x+dx[i]==M-1) is_visit[N-1][M-1]=true;
                            
                        wall.push(pair<pair<int,int>,bool>(pair<int,int>(x+dx[i],y+dy[i]),is_use));
                    }
                }
            }


        }
        cnt++;

    }

    //if (ans == N * M)
        //printf("-1\n");
    //else
        printf("%d", ans);

    return 0;
}
bool is_map(int x, int y)
{
    if(x < 0 || y < 0 || x>=M || y>=N) return false;
    return true;
}
void bfs(int x, int y, int now, bool is_remove)
{
    //printf("%d %d\n", x, y);
    if (x < 0 || y < 0 || x >= M || y >= N)
    {
        return;
    }
    if (now > ans)
        return;
    if (is_visit[y][x])
        return;
    if(ans ==N*M) return;
    if (y == N - 1 && x == M - 1)
    {
        ans = now;
    }
    if (map[y][x] == 0)
    {
        is_visit[y][x] = true;
        bfs(x + 1, y, now + 1, is_remove);
        if (is_remove)
            is_visit[y][x] = false;
        is_visit[y][x] = true;
        bfs(x, y + 1, now + 1, is_remove);
        if (is_remove)
            is_visit[y][x] = false;
        is_visit[y][x] = true;
        bfs(x - 1, y, now + 1, is_remove);
        if (is_remove)
            is_visit[y][x] = false;
        is_visit[y][x] = true;
        bfs(x, y - 1, now + 1, is_remove);
        if (is_remove)
            is_visit[y][x] = false;
        return;
    }
    if (map[y][x] == 1)
    {
        if (!is_remove)
        {
            bfs(x + 1, y, now + 1, true);
            bfs(x, y + 1, now + 1, true);
            bfs(x - 1, y, now + 1, true);
            bfs(x, y - 1, now + 1, true);
        }
        return;
    }
    
}