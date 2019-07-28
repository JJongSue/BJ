#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    vector<vector<int>> map(N + 2, vector<int>(N + 2, 0));
    vector<vector<char>> answer(N, vector<char>(N, '0'));
    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            char tmp;
            scanf(" %c", &tmp);
            if (tmp == '.')
                map[i][j] = 0;
            else
                map[i][j] = (int)(tmp - '0');
        }
    }
    /* for(int i=1;i<N+1;i++)
    {
        for(int j=1;j<N+1;j++)
        {
            printf("%d", map[i][j]);
        }
        printf("\n");

    }*/

    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            int count = 0;
            if (map[i][j] != 0)
                //answer[i-1][j-1]='*';
                printf("*");
            else
            {

                for (int dx = -1; dx <= 1; dx++)
                {
                    for (int dy = -1; dy <= 1; dy++)
                    {
                        count += map[i + dy][j + dx];
                    }
                }
                //answer[i-1][j-1] = count;
                if (count >= 10)
                    printf("M");
                else
                    printf("%d", count);
            }
        }
        printf("\n");
    }
    return 0;
}