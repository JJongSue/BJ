#include <iostream>
#include <vector>
using namespace std;

static vector<vector<bool>> map(10, vector<bool>(10, false));
static vector<int> paper(5,5);
static int ans = 0;
int main()
{
    //map(10, vector<bool>(10, false));
    int tmp, onecnt=0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            scanf("%d", &tmp);
            if (tmp == 1)
            {
                map[i][j] = true;
                onecnt++;
            }
                
        }
    }
    if(onecnt == 100){
        printf("4\n");
    }
    else if(onecnt == 0){
        printf("0\n");
    }
    else{

    }
    
    int p = 8;
    bool end = false;
    for (int i = 0; i <= 10 - p; i++)
        {
            if (end)
                break;
            for (int j = 0; j <= 10 - p; j++)
            {
                if (end)
                    break;
                for (int y = i; y <= i + p-1; y++)
                {
                    if (end)
                    break;
                    for (int x = j; x <= j + p-1; x++)
                    {
                        if (!map[y][x])
                        {
                            end = true;
                            break;
                        }
                    }
                }
                if (!end)
                {
                    for (int y = i; y <= i + p-1; y++)
                    {
                        for (int x = j; x <= j + p-1; x++)
                        {
                            map[y][x] = false;
                        }
                    }
                    paper[3]=1;
                    ans+=4;
                }
            }
        }
        p = 6;
        end = false;
        for (int i = 0; i <= 10 - p; i++)
        {
            if (end)
                break;
            for (int j = 0; j <= 10 - p; j++)
            {
                if (end)
                    break;
                for (int y = i; y <= i + p-1; y++)
                {
                    if (end)
                    break;
                    for (int x = j; x <= j + p-1; x++)
                    {
                        if (!map[y][x])
                        {
                            end = true;
                            break;
                        }
                    }
                }
                if (!end)
                {
                    for (int y = i; y <= i + p-1; y++)
                    {
                        for (int x = j; x <= j + p-1; x++)
                        {
                            map[y][x] = false;
                        }
                    }
                    paper[2]=1;
                    ans+=4;
                }
            }
        }



    
    /*printf("\n");
    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 10; x++)
        {
            if(map[y][x]) printf("1 ");
            else printf("0 ");
            
        }printf("\n");
    }*/

    bool is_ok = true;
    for (int i = 0; i < 10; i++)
    {
        if(!is_ok) break;
        for (int j = 0; j < 10; j++)
        {
            if (map[i][j])
            {
                is_ok = false;
                break;
            }
        }
    }
    if (is_ok)
        printf("%d\n", ans);
    else
        printf("-1\n");
    return 0;
}

void go(int x, int y)
{
    for (int p = 5; p > 0; p--)
    {
        for (int i = 0; i <= 10 - p; i++)
        {
            if (paper[p-1] == 0)
                break;
            for (int j = 0; j <= 10 - p; j++)
            {
                if (paper[p-1] == 0)
                    break;
                bool is_p = true;
                for (int y = i; y <= i + p-1; y++)
                {
                    if (!is_p)
                        break;
                    for (int x = j; x <= j + p-1; x++)
                    {
                        if (!map[y][x])
                        {
                            is_p = false;
                            break;
                        }
                    }
                }
                if (is_p)
                {
                    for (int y = i; y <= i + p-1; y++)
                    {
                        for (int x = j; x <= j + p-1; x++)
                        {
                            map[y][x] = false;
                        }
                    }
                    paper[p-1]--;
                    ans++;
                }
            }
        }
    }
}