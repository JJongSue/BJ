#include<iostream>
#include<vector>
using namespace std;
vector<vector <char>> map;
static int R, C;
static int sheep, wolf;
void find(int x, int y);


int main(void)
{
    scanf("%d %d", &R, &C);
    map.assign(R, vector<char>(C, 0));
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            scanf(" %c", &map[i][j]);
        }
    }
    int answ=0, anss=0;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            sheep=0;
            wolf=0;
            if(map[i][j] == '/' || map[i][j] == '#') continue;
            find(j,i);
            if(wolf >= sheep) answ+=wolf;
            else anss+=sheep;            
        }
    }
    printf("%d %d\n", anss, answ);




}
void find(int x, int y)
{
    
    if(y < 0 || x < 0 || x >= C || y >= R) return;
    
    if(map[y][x] == '/') return;
    if(map[y][x] == '#') return;
    //printf("%d %d\n",x,y);
    if(map[y][x] == 'o') {sheep++; }
    if(map[y][x] == 'v') {wolf++; }
    map[y][x]='/';
    find(x+1,y);
    find(x-1,y);
    find(x,y+1);
    find(x,y-1);
    


}