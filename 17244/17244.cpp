#include<iostream>
#include<vector>
using namespace std;
static int N, M;
static vector<vector<char>> map;
static int ans = 50*50*7;
static int cnt;
bool is_map(int x, int y);
void bfs(int x, int y, int product, int now);
int main(void)
{
    scanf("%d %d", &M, &N);
    map.assign(N, vector<char>(M, '.'));
    //vector<pair<int,int>> xxy;
    cnt = 0;
    pair<int, int> start;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            scanf(" %1c", &map[i][j]);
            if(map[i][j] == 'S') start = pair<int, int>(j,i);
            if(map[i][j] == 'X') cnt++;
            /*{
                xxy.push_back(pair<int,int>(j,i));
            }*/
        }
    }
    /*for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            printf("%c", map[i][j]);
        }printf("\n");
    }*/
    //printf("%d %d", start.first, start.second);
    bfs(start.first, start.second, 0, 0);
    printf("%d\n", ans);
    return 0;
}
void bfs(int x, int y, int product, int now)
{
    
    if(!is_map(y,x)) return;
    if(now > ans) return;
    if(map[y][x] == 'E'){
        if(product == cnt){
            if(now < ans) ans = now;
        }
        return;
    }
    //printf("%d %d\n", x,y);
    if(map[y][x] == 'X'){

        map[y][x] = '.';
        bfs(x+1,y,product+1,now+1);
        bfs(x-1,y,product+1,now+1);
        bfs(x,y+1,product+1,now+1);
        bfs(x,y-1,product+1,now+1);
        map[y][x] = 'X';
        return;
    }
    if(map[y][x] == '.' || map[y][x] == 'S')
    {
        bfs(x+1,y,product,now+1);
        bfs(x-1,y,product,now+1);
        bfs(x,y+1,product,now+1);
        bfs(x,y-1,product,now+1);
    }

    return;


}
bool is_map(int x, int y)
{
    if(y<0 || y>=N || x<0 || x>=M) return false;
    return true;
}