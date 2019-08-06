#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
static int N;
vector<vector <int>> map;
void spread(int n, int y, int x);
int main(void)
{
    N=0;
    scanf("%d", &N);
    map.assign(N, vector<int>(N,0));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }
    int iter = 2;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(map[i][j] == 1)
            {
                spread(iter, i, j);
                iter++;
            }

        }
    }
    vector<int> ans(iter,0);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {            
            if(map[i][j] != 0) ans[map[i][j]]++;
        }        
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", iter-2);
    for(int i=2;i<ans.size();i++)
        printf("%d\n", ans[i]);
    return 0;
}
void spread(int n, int y, int x)
{
    if(y < 0 || x < 0 || x > N-1 || y>N-1) return;

    if(map[y][x] == 1)
    {
        map[y][x] = n;
        spread(n,y+1,x);
        spread(n,y-1,x);
        spread(n,y,x+1);
        spread(n,y,x-1);
    }
    else return;
}