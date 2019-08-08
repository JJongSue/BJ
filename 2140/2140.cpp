#include <iostream>
#include <vector>
using namespace std;
static vector<vector<int>> map;
static int N;
void set_arround(int x, int y, int num);
int count_mine(int x, int y, int find);
bool is_end();
int main(void)
{
    N = 0;
    scanf("%d", &N);
    map.assign(N, vector<int>(N, -10));
    char tmp = 0;
    if (N == 1 || N == 2)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                scanf(" %1c", &map[i][j]);
        }
        printf("0");
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                scanf(" %1c", &tmp);
                if (tmp >= '0' && tmp <= '9')
                    map[i][j] = (tmp - '0');
            }
        }
        //bool is_end = true;
        while (is_end())
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (map[i][j] == 0)
                    {
                        if (count_mine(j, i, -1) == 0)
                        {
                            set_arround(j, i, -5);
                        }
                    }
                    else if (map[i][j] > 0)
                    {
                        int cnt =count_mine(j, i, -1);
                        if ( cnt == map[i][j])
                        {
                            set_arround(j, i, -5);
                        }
                        else if(cnt+count_mine(j,i,-10) == (map[i][j]))
                        {
                            set_arround(j, i, -1);
                        }
                    }
                }
            }

        }

        int mine = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                //printf("%3d",map[i][j]);
                if (map[i][j] == -1)
                    mine++;
            }
            //printf("\n");            
        }
        for(int i=2;i<N-2;i++)
        {
            for(int j=2;j<N-2;j++)
            {
                mine++;
            }
        }
        printf("%d", mine);
    }

    return 0;
}

int count_mine(int x, int y, int find)
{
    int mine = 0;
    for (int k = -1; k <= 1; k++)
    {
        if (y + k < 0 || y + k >= N)
            continue;
        for (int l = -1; l <= 1; l++)
        {
            if (x + l < 0 || x + l >= N)
                continue;
            if (map[y + k][x + l] == find)
                mine++;
        }
    }
    return mine;
}
void set_arround(int x, int y, int num)
{
    for (int k = -1; k <= 1; k++)
    {
        if (y + k < 0 || y + k >= N)
            continue;
        for (int l = -1; l <= 1; l++)
        {
            if (x + l < 0 || x + l >= N)
                continue;
            if (l == 0 && k == 0)
                continue;
            if (map[y + k][x + l] == -10)
                map[y + k][x + l] = num;
        }
    }
}
bool is_end()
{
    for(int i=1;i<N-1;i++)
    {
        if(map[1][i] == -10) return true;
    }
    for(int i=1;i<N-1;i++)
    {
        if(map[i][1] == -10) return true;
    }
    for(int i=1;i<N-1;i++)
    {
        if(map[N-2][i] == -10) return true;
    }
    for(int i=1;i<N-1;i++)
    {
        if(map[i][N-2] == -10) return true;
    }
    return false;
    
}