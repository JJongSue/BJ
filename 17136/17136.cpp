#include <iostream>
#include <vector>
using namespace std;
static vector<vector<bool>> map(10, vector<bool>(10, false));
static vector<int> paper(5, 5);
static int ans = 10e8;
void find_ans(int now, int cnt);
int main()
{

    int tmp;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            scanf("%d", &tmp);
            if (tmp == 1)
                map[i][j] = true;
        }
    }

    find_ans(0, 0);
    if (ans == 10e8)
        printf("-1\n");
    else
        printf("%d\n", ans);
    return 0;
}
void find_ans(int now, int cnt)
{
    //printf("%d %d\n", now, cnt);
    if (cnt > ans)
        return;
    if (now == 99)
    {
        if(map[9][9] == true)
        {
            if(paper[0]==0) return;
            else if(ans > cnt+1) ans = cnt+1;
        }
        else ans = cnt;
        return;
    }
    if (!map[now / 10][now % 10])
    {
        find_ans(now + 1, cnt);
        return;
    }
    else
    {
        for (int p = 5; p > 0; p--)
        {    
            if (paper[p - 1] == 0)
                continue;
            if (now / 10 + p - 1 > 9 || now % 10 + p - 1 > 9)
                continue;
            bool is_ok = true;
            //printf("%d %d %d\n", now, cnt, p);
            for (int i = now / 10; i <= now / 10 + p - 1; i++)
            {
                if (!is_ok)
                    break;
                for (int j = now % 10; j <= now % 10 + p - 1; j++)
                {
                    //printf("%d %d\n", i, j);
                    if (!map[i][j])
                    {
                        is_ok = false;
                        break;
                    }
                }
            }
            
            if (!is_ok)
                continue;
            paper[p - 1]--;
            for (int i = now / 10; i <= now / 10 + p - 1; i++)
            {
                for (int j = now % 10; j <= now % 10 + p - 1; j++)
                {
                    map[i][j] = false;
                }
            }
            //printf("%d %d %d\n", now, cnt, p);
            find_ans(now + 1, cnt + 1);
            for (int i = now / 10; i <= now / 10 + p - 1; i++)
            {
                for (int j = now % 10; j <= now % 10 + p - 1; j++)
                {
                    map[i][j] = true;
                }
            }
            paper[p - 1]++;
        }
    }
}