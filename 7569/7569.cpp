#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//static vector<vector<vector<int>>> map;
static int  map[100][100][100];
//static vector<vector<int>> answer;
//static vector<pair<int, int>> maketo;
//static vector<vector<bool>> is_visted;
static queue<pair< pair <int, int>, int>> one;
static queue<pair< pair <int, int>, int>> tmp_q;
static int M, N, H;
bool input(int x, int y, int h);
//void dfs(int x, int y, int cnt);

int main(void)
{
    //M가로의 개수, N세로의 개수
    scanf("%d %d %d", &M, &N, &H);
    //map.assign(H, vector(N, vector<int>(M, 0)));
    //answer.assign(N,vector<int>(M,-1));
    //s_visted.assign(N,vector<bool>(M,false));
    for (int k = 0; k < H; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                scanf("%d", &map[k][i][j]);
                //if(map[i][j] == -1) answer[i][j] == -1;
                if (map[k][i][j] == 1)
                {
                    int tmp[3] = {k, i, j};
                    //one.push(pair<pair<int,int>, int>(pair(j ,i), k));
                    one.push(pair<pair<int,int>, int>(pair<int,int>(j,i),k)  );
                }
            }
        }
    }

    bool is_end = true;
    long long now = 0;
    static queue<pair< pair <int, int>, int>> empty;
    tmp_q = empty;
    while (is_end)
    {
        while (!one.empty())
        {
            int h = one.front().second;
            int x = one.front().first.first;
            int y = one.front().first.second;
            one.pop();

            //answer[y][x] = now;
            if (input(x + 1, y, h))
            {  
                tmp_q.push(pair<pair<int,int>, int>(pair<int,int>(x+1 ,y), h));
                map[h][y][x + 1] = 1;
            }
            if (input(x - 1, y, h))
            {
                tmp_q.push(pair<pair<int,int>, int>(pair<int,int>(x-1 ,y), h));
                map[h][y][x - 1] = 1;
            }
            if (input(x, y + 1, h))
            {
                tmp_q.push(pair<pair<int,int>, int>(pair<int,int>(x ,y+1), h));
                map[h][y + 1][x] = 1;
            }
            if (input(x, y - 1, h))
            {
                tmp_q.push(pair<pair<int,int>, int>(pair<int,int>(x ,y-1), h));
                map[h][y - 1][x] = 1;
            }
            if (input(x, y, h + 1))
            {
                tmp_q.push(pair<pair<int,int>, int>(pair<int,int>(x ,y), h+1));
                map[h + 1][y][x] = 1;
            }
            if (input(x , y, h - 1))
            {
                tmp_q.push(pair<pair<int,int>, int>(pair<int,int>(x ,y), h-1));
                map[h - 1][y][x] = 1;
            }
        }

        if (tmp_q.empty())
            break;

        one = tmp_q;
        tmp_q = empty;
        now++;
    }

    bool is_ok = true;
    int min = 0;
    for (int k = 0; k < H; k++)
    {
        if(is_ok == false) break;
        for (int i = 0; i < N; i++)
        {
            if (is_ok == false)
                break;
            for (int j = 0; j < M; j++)
            {
                if (map[k][i][j] == 0)
                {
                    is_ok = false;
                    break;
                }
            }
        }
    }

    if (is_ok)
        printf("%d\n", now);
    else
        printf("%d\n", -1);
    return 0;
}

bool input(int x, int y, int h)
{
    if (x < 0 || y < 0 || x >= M || y >= N || h < 0 || h >= H)
        return false;
    if (map[h][y][x] == 0)
        return true;
    return false;
    //if(map[y][x] == -1 ) {return false; }
    /*if(map[y][x] == 1 || map[y][x] == -1) return false;
    return true;*/
}
