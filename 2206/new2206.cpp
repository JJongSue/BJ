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
static vector<vector<int>> is_visit;
static vector<vector<int>> is_visit2;
static int N, M;
void bfs(int x, int y, int now, bool is_remove);
bool is_map(int x, int y);
int main(void)
{
    scanf("%d %d", &N, &M);
    map.assign(N, vector<int>(M, 0));
    is_visit.assign(N, vector<int>(M, -1));
    is_visit2.assign(N, vector<int>(M, -1));
    queue<pair<pair<int,int>,bool>> wall;
    ans = N * M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%1d", &map[i][j]);
            /*if (map[i][j] == 1)
                {
                    is_visit2[i][j] = 0;
                    is_visit[i][j] = 0;
                }*/
        }
    }
    //int tmp[3] = {0,0,0};
    wall.push(pair<pair<int,int>,bool>(pair<int,int>(0,0), false));
    int cnt =1;
    int ans = -1;
    queue<pair<pair<int,int>,bool>> q_empty;
    is_visit[0][0]= 1;
    is_visit2[0][0]= 1;
    while(!wall.empty())
    {        
        if(is_visit[N-1][M-1]!=-1 || is_visit2[N-1][M-1]!=-1){
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
            for(int i=0;i<4;i++)
            {
                if(!is_map(x+dx[i],y+dy[i])) continue;
                if(is_visit[y+dy[i]][x+dx[i]] != -1) continue;
                if(!is_use)
                {
                    
                    if(map[y+dy[i]][x+dx[i]] == 0)
                    {
                        is_visit[y+dy[i]][x+dx[i]]=cnt+1;
                        if(is_visit2[y+dy[i]][x+dx[i]] == -1) is_visit2[y+dy[i]][x+dx[i]] =cnt+1;
                        wall.push(pair<pair<int,int>,bool>(pair<int,int>(x+dx[i],y+dy[i]),false));
                        continue;
                    }
                    else
                    {
                        if(is_visit2[y+dy[i]][x+dx[i]] != -1) continue;
                        is_visit2[y+dy[i]][x+dx[i]] = cnt+1;
                        wall.push(pair<pair<int,int>,bool>(pair<int,int>(x+dx[i],y+dy[i]),true));
                        continue;
                    }

                }
                else
                {
                    if(map[y+dy[i]][x+dx[i]] == 0 && is_visit2[y+dy[i]][x+dx[i]] == -1)
                    {
                        
                        is_visit2[y+dy[i]][x+dx[i]]=cnt+1;                        
                        wall.push(pair<pair<int,int>,bool>(pair<int,int>(x+dx[i],y+dy[i]),true));
                        continue;
                    }
                    else
                    {
                        continue;
                    }
                }
               
            }


        }
        cnt++;

    }

    //if (ans == N * M)
        //printf("-1\n");
    //else
    int min = 10e8;
    if(is_visit2[N-1][M-1] == -1 && is_visit[N-1][M-1] == -1) printf("-1\n", ans);
    else
    {
        if(is_visit[N-1][M-1] != -1) min = is_visit[N-1][M-1];
        if(is_visit2[N-1][M-1] != -1 && min > is_visit2[N-1][M-1]) min = is_visit2[N-1][M-1];
        printf("%d\n", min);
    }
    

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