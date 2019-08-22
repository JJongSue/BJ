#include <iostream>
#include <vector>
using namespace std;
static bool is_visit[5][5][5];
static bool map[5][4][5][5];
static bool find_map[5][5][5];
static int dxyz[6][3] = {{-1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {0, 0, 1}, {0, 0, -1}, {1, 0, 0}};
static int ans = -1;
static bool select1[5]={false,};
void set_map(int z);
bool is_map(int x, int y, int z);
void go(int x, int y, int z, int cnt);
void select_map(int z);
int main(void)
{
    // 5*5가 5개인 미로가 주어짐
    // 0갈 수 없는 칸, 1갈 수 있는 칸
    //0,0,0에서 5,5,5까지 감\
    //미로를 돌릴수 있음
    int tmp;
    for (int z = 0; z < 5; z++)
    {
        for (int y = 0; y < 5; y++)
        {
            for (int x = 0; x < 5; x++)
            {
                scanf("%d", &tmp);
                if (tmp)
                    map[z][0][y][x] = true;
                else
                    map[z][0][y][x] = false;
            }
        }
        set_map(z);
        /*for(int see=0;see<4;see++)
        {
            for(int i=0;i<5;i++)
            {
                for(int j=0;j<5;j++)
                {
                    if(map[z][see][i][j]) printf("1");
                    else printf("0");                    
                }
                printf("\n");
            }printf("\n\n");
        }*/
    }
    select_map(0);
    printf("%d", ans);

    return 0;
}
void set_map(int z)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            //오른쪽으로 90도 돌렸을때
            map[z][1][j][4 - i] = map[z][0][i][j];
            //오른쪽으로 180도
            map[z][2][4 - j][i] = map[z][0][i][j];
            //왼쪽으로 90도
            map[z][3][4 - i][4 - j] = map[z][0][i][j];
        }
    }
}
void select_map(int z)
{
    if (z == 5)
    {
        is_visit[0][0][0] = true;   
        go(0, 0, 0, 0);
        is_visit[0][0][0] = false;   
        return;
    }
    if (z == 0)
    {
        for (int iter = 0; iter < 5; iter++)
        {
            for (int i = 0; i < 4; i++)
            {
                if (map[iter][i][0][0])
                {
                    for (int x = 0; x < 5; x++)
                    {
                        for (int y = 0; y < 5; y++)
                        {
                            find_map[z][y][x] = map[iter][i][y][x];
                        }
                    }
                    select1[iter] = true;
                    select_map(z + 1);
                    select1[iter] = false;
                }
            }
        }
        return;
    }
    for (int iter = 0; iter < 5; iter++)
    {
        if (select1[iter])
            continue;
        for (int i = 0; i < 4; i++)
        {
            for (int x = 0; x < 5; x++)
            {
                for (int y = 0; y < 5; y++)
                {
                    find_map[z][y][x] = map[iter][i][y][x];
                }
            }
            select1[iter] = true;
            select_map(z + 1);
            select1[iter] = false;
        }
    }
    return;
}
void go(int x, int y, int z, int cnt)
{
    if(!find_map[4][4][4]) return;
    if (ans == 12)
        return;
    if (ans != -1 && cnt >= ans)
        return;
    if(cnt >= 125) return;
    //printf("%d %d %d\n", x,y,z);
    if (x == 4 && y == 4 && z == 4)
    {
        ans = cnt;
        return;
    }
    for (int i = 0; i < 6; i++)
    {
        int dx = x + dxyz[i][2];
        int dy = y + dxyz[i][1];
        int dz = z + dxyz[i][0];
        if (is_map(dx, dy, dz))
        {
            is_visit[dz][dy][dx] = true;
            go(dx, dy, dz, cnt + 1);
            is_visit[dz][dy][dx] = false;
        }
    }
    return;
}
bool is_map(int x, int y, int z)
{
    if (x < 0 || y < 0 || z < 0 || x >= 5 || y >= 5 || z >= 5)
        return false;
    if (find_map[z][y][x] == false)
        return false;
    if (is_visit[z][y][x])
        return false;
    return true;
}