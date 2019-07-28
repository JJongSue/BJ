#include <iostream>
#include <vector>
using namespace std;
static vector<vector<int>> map;
static vector<vector<int>> answer;
static vector<vector<int>> answer2;
static int R, C, T;
static int pos[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void extend();
void move(int ry);
int main(void)
{
    scanf("%d %d %d", &R, &C, &T);
    map.assign(R + 2, vector<int>(C + 2, -1));
    answer.assign(R, vector<int>(C, -1));
    //vector<vector <int>> map(R+2, vector<int>(C+2, -1));
    int ry1 = 0;
    bool findR = true;
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            scanf("%d", &map[i][j]);
            if (findR == true && map[i][j] == -1)
            {
                ry1 = i - 1;
                findR = false;
            }
        }
    }
    extend();
        answer2 = answer;
        move(ry1);

        answer = answer2;



    for (int iter = 1; iter < T; iter++)
    {
        for (int i = 1; i <= R; i++)
        {
            for (int j = 1; j <= C; j++)
            {
                map[i][j] = answer[i-1][j-1];
            }
        }
        extend();
        answer2 = answer;
        move(ry1);
        answer = answer2;
    }

    /*  extend();
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            printf("%d ", answer[i][j]);
            //ans+= answer[i][j];
        }
        printf("\n");
    }
    answer2= answer;*/
    //move(ry1);
    int ans = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            ans += answer2[i][j];
        }
    }
    printf("%d", ans + 2);

    return 0;
}
void extend()
{
    //vector <vector <int>> tmp(R, vector<int>(C,0));
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {

            if (map[i][j] == -1)
            {
                //tmp[i-1][j-1]=-1;
                answer[i - 1][j - 1] = -1;
                continue;
            }

            else
            {
                int tmpans = 0;
                int wall = 0;
                for (int k = 0; k < 4; k++)
                {
                    int dx = j + pos[k][1];
                    int dy = i + pos[k][0];
                    if (map[dy][dx] != -1)
                    {
                        wall++;
                        tmpans += (map[dy][dx] / 5);
                    }
                }
                answer[i - 1][j - 1] = tmpans + (map[i][j] - ((map[i][j] / 5) * wall));
            }
        }
    }
    //map.clear();
}
void move(int ry)
{
    for(int i=2;i<C;i++)
    {
        answer2[ry][i]=answer[ry][i-1];
    }
    answer2[ry][1]=0;
    for(int i=ry-1;i>=0;i--)
    {
        answer2[i][C-1] = answer[i+1][C-1];
    }
    for(int i=C-2;i>=0;i--)
    {
        answer2[0][i]=answer[0][i+1];
    }
    for(int i=1;i<ry;i++)
    {
        answer2[i][0] = answer[i-1][0];
    }

    int tmp = 0;
   
    // start
    tmp = 0;

    int tmp1 = 0;
    for (int i = 2; i < C; i++)
    {
        tmp1 = answer[ry + 1][i];
        answer2[ry + 1][i] = answer[ry + 1][i - 1];
    }
    answer2[ry + 1][1] = 0;
    for (int i = ry + 2; i < R; i++)
    {
        tmp = answer[i][C - 1];
        answer2[i][C - 1] = answer[i - 1][C - 1];
    }

    //answer[ry+2][C-1] = tmp1;
    for (int i = C - 2; i >= 0; i--)
    {
        tmp1 = answer[R - 1][i];
        answer2[R - 1][i] = answer[R - 1][i + 1];
    }
    //answer[R-1][C-2]=tmp;

    for (int i = R - 2; i >= ry + 2; i--)
    {
        tmp = answer[i][0];
        answer2[i][0] = answer[i + 1][0];
    }
    //answer[R-2][0]=tmp1;
}