#include <iostream>
#include <vector>
#include <queue>
using namespace std;
static int answer;
static queue<pair<int, int>> fire_tmp;
static queue<pair<int, int>> fire;
static queue<pair<int, int>> man;
static queue<pair<int, int>> man_tmp;
static queue<pair<int, int>> nothing;
static int w, h;
static vector<vector<char>> smem;
static vector<vector<char>> map;
bool is_go(int x, int y);
bool is_fire(int x, int y);
void solve(int cnt);

int main(void)
{
    int test = 0;
    scanf("%d", &test);
    for (int test_i = 1; test_i <= test; test_i++)
    {
        fire=nothing;
        fire_tmp=nothing;
        man=nothing;
        man_tmp=nothing;

        int man_x, man_y;
        answer = -1;
        scanf("%d %d", &w, &h);
        fire = nothing;
        //fire_tmp = nothing;
        map.clear();
        map.assign(h + 2, vector<char>(w + 2, '.'));

        for (int i = 1; i <= h; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                scanf(" %1c", &map[i][j]);   
                if (map[i][j] == '*')
                    fire.push(pair<int, int>(j, i));
                else if (map[i][j] == '@')
                {
                    man.push(pair<int, int>(j, i));
                    man_y = i;
                    man_x = j;
                }
            }
        }
        /*for(int i=0;i<h+2;i++)
        {
            for(int j=0;j<w+2;j++)
                printf("%c", map[i][j]);
            printf("\n");
        }*/

        solve(0);
        if (answer == -1)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n", answer);
    }
    return 0;
}
void solve(int cnt)
{
    
    if (man.empty())
        return;

    while (!man.empty())
    {
        int x = man.front().first;
        int y = man.front().second;
        man.pop();
        if (x < 0 || y < 0 || x > w + 2 || y > h + 2)
        {
            continue;
        }
        man_tmp.push(pair<int, int>(x, y));
        if (x == 0 || y == 0 || x == w + 1 || y == h + 1)
        {

            if (answer == -1)
            {
                answer = cnt;
            }
            else
            {
                if (answer > cnt)
                {
                    answer = cnt;
                }
            }
            return;
        }
    }
    
    man=man_tmp;
    man_tmp=nothing;
    if (answer != -1 && answer < cnt)
        return;

    while (!fire.empty())
    {
        int f_x = fire.front().first;
        int f_y = fire.front().second;
        fire.pop();
        if (is_fire(f_x + 1, f_y))
        {
            fire_tmp.push(pair<int, int>(f_x + 1, f_y));
            map[f_y][f_x + 1] = '*';
        }
        if (is_fire(f_x - 1, f_y))
        {
            map[f_y][f_x - 1] = '*';
            fire_tmp.push(pair<int, int>(f_x - 1, f_y));
        }

        if (is_fire(f_x, f_y + 1))
        {
            map[f_y + 1][f_x] = '*';
            fire_tmp.push(pair<int, int>(f_x, f_y + 1));
        }

        if (is_fire(f_x, f_y - 1))
        {
            map[f_y - 1][f_x] = '*';
            fire_tmp.push(pair<int, int>(f_x, f_y - 1));
        }
    }
    
    /*for (int i = 0; i < h + 2; i++)
        {
            for (int j = 0; j < w + 2; j++)
            {
                printf("%c", fcp[i][j]);
            }
            printf("\n");
        }*/

    fire = fire_tmp;
    fire_tmp = nothing;
    while (!man.empty())
    {
        int x = man.front().first;
        int y = man.front().second;
        man.pop();
        if (is_go(x + 1, y))
        {
            map[y][x+1]='@';
            man_tmp.push(pair<int, int>(x+1, y));

        }
        if (is_go(x - 1, y))
        {
            map[y][x-1]='@';
            man_tmp.push(pair<int, int>(x-1, y));
        }
        if (is_go(x, y + 1))
        {
            map[y+1][x]='@';
            man_tmp.push(pair<int, int>(x, y+1));
        }
        if (is_go(x, y - 1))
        {
            map[y-1][x]='@';
            man_tmp.push(pair<int, int>(x, y-1));
        }
    }
    man=man_tmp;
    man_tmp=nothing;
    solve(cnt+1);
    /*for(int i=0;i<h+2;i++)
        {
            for(int j=0;j<w+2;j++)
                printf("%c", map[i][j]);
            printf("\n");
        }*/
}
bool is_fire(int x, int y)
{
    if (x < 1 || y < 1 || x > w || y > h)
        return false;
    if (map[y][x] == '#' || map[y][x] == '*')
        return false;
    else
        return true;
}
bool is_go(int x, int y)
{
    if (map[y][x] == '.')
        return true;
    return false;
}