#include<iostream>
#include<vector>
vector<vector<int>> map;
vector<vector<int>> answer;
vector<pair<int, int>> maketo;
int M, N;
int dfs(int x, int y, int cnt);
using namespace std;
int main(void)
{
    //M가로의 개수, N세로의 개수
    scanf("%d %d", &M, &N);
    map.assign(N,vector<int>(M,0));
    answer.assign(N,vector<int>(M,N*M+2));    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            scanf("%d", map[i][j]);
            if(map[i][j] == -1) answer[i][j] == -1;
            if(map[i][j]==1)
            {                
                maketo.push_back(pair<int,int>(i,j));
            }
        }
    }
    return 0;
}
int dfs(int x, int y, int cnt)
{
    if(x<0 || y<0 || x>=M || y>=N) return;
    if(map[y][x] == -1) return;
    
}