#include <iostream>
#include <vector>
using namespace std;

static int N;
static vector<vector<int>> map;
static vector<vector<int>> copy_map;
static int ans = 0;

void right();
void left();
void up();
void down();
void find_max(int cnt);
int main(void)
{
    scanf("%d", &N);
    map.assign(N, vector<int>(N, 0));
    copy_map.assign(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf(" %d", &map[i][j]);
        }
    }
    find_max(0);
    printf("%d\n", ans);
    
    copy_map = map;
    right(); down(); left();
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%3d ", map[i][j]);
        }printf("\n");
    }printf("\n\n");
/*
    //map = copy_map;
    right();
     for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%3d ", map[i][j]);
        }printf("\n");
    }printf("\n\n");

    //map = copy_map;
    //up(); left();
    right();
     for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%3d ", map[i][j]);
        }printf("\n");
    }printf("\n\n");

    //map = copy_map;
    up();//down();
     for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%3d ", map[i][j]);
        }printf("\n");
    }printf("\n\n");
    right();//down();
     for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%3d ", map[i][j]);
        }printf("\n");
    }printf("\n\n");*/
    return 0;
}

void left()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] != 0)
            {
                int k = 0;
                for (k = j + 1; k < N; k++)
                {
                    if (map[i][k] == 0)
                        continue;
                    if (map[i][j] == map[i][k])
                    {
                        map[i][j] *= 2;
                        map[i][k] = 0;
                    }
                    else
                    {
                        map[i][j + 1] = map[i][k];
                        if (k != j + 1)
                            map[i][k] = 0;
                    }
                    break;
                }
            }
            else
            {
                if (j == N - 1)
                    break;
                int k = 0;
                for (k = j + 1; k < N; k++)
                {
                    if (map[i][k] == 0)
                        continue;
                    map[i][j] = map[i][k];
                    map[i][k] = 0;
                    j--;
                    break;
                }
            }
        }
    }
}
void right()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = N - 1; j >= 0; j--)
        {
            if (map[i][j] != 0)
            {
                int k = 0;
                for (k = j - 1; k >= 0; k--)
                {
                    if (map[i][k] == 0)
                        continue;
                    if (map[i][j] == map[i][k])
                    {
                        map[i][j] *= 2;
                        map[i][k] = 0;
                    }
                    else
                    {
                        map[i][j - 1] = map[i][k];
                        if (j - 1 != k)
                            map[i][k] = 0;
                    }
                    break;
                }
            }
            else
            {
                if (j == 0)
                    break;
                int k = 0;
                for (k = j - 1; k >= 0; k--)
                {
                    if (map[i][k] == 0)
                        continue;
                    map[i][j] = map[i][k];
                    map[i][k] = 0;
                    j++;
                    break;
                }
            }
        }
    }
}
void up()
{
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < N; i++)
        {
            if (map[i][j] != 0)
            {
                int k = 0;
                for (k = i + 1; k < N; k++)
                {
                    if (map[k][j] == 0)
                        continue;
                    if (map[i][j] == map[k][j])
                    {
                        map[k][j] = 0;
                        map[i][j] *= 2;
                    }
                    else
                    {
                        map[i + 1][j] = map[k][j];
                        if (i + 1 != k)
                            map[k][j] = 0;
                    }

                    break;
                }
            }
            else
            {
                if (i == N - 1)
                    break;
                int k = 0;
                for (k = i + 1; k < N; k++)
                {
                    if (map[k][j] == 0)
                        continue;
                    map[i][j] = map[k][j];
                    map[k][j] = 0;
                    i--;
                    break;
                }
            }
        }
    }
}
void down()
{
    for (int j = 0; j < N; j++)
    {
        for (int i = N - 1; i >= 0; i--)
        {
            if (map[i][j] != 0)
            {
                int k = 0;
                for (k = i - 1; k >= 0; k--)
                {
                    if (map[k][j] == 0)
                        continue;
                    if (map[i][j] == map[k][j])
                    {
                        map[i][j] *= 2;
                        map[k][j] = 0;
                    }
                    else
                    {
                        map[i - 1][j] = map[k][j];
                        if (i - 1 != k)
                            map[k][j] = 0;
                    }

                    break;
                }
            }
            else
            {
                if (i == 0)
                    break;
                int k = 0;
                for (k = i - 1; k >= 0; k--)
                {
                    if (map[k][j] == 0)
                        continue;
                    map[i][j] = map[k][j];
                    map[k][j] = 0;
                    i++;
                    break;
                }
            }
        }
    }
}
void find_max(int cnt)
{
    if (cnt == 5)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (ans < map[i][j])
                    ans = map[i][j];
            }
        }
        return;
    }
    vector<vector<int>> tmp = map;
    left();
    find_max(cnt + 1);
    map = tmp;
    right();
    find_max(cnt + 1);
    map = tmp;
    up();
    find_max(cnt + 1);
    map = tmp;
    down();
    find_max(cnt + 1);
    map = tmp;
}