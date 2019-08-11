#include<iostream>
#include<vector>
#include<queue>
using namespace std;
static vector<vector<int>> map;
//static vector<vector<int>> answer;
//static vector<pair<int, int>> maketo;
//static vector<vector<bool>> is_visted;
static queue<pair<int,int>> one;
static queue<pair<int,int>> tmp_q;
static int M, N;
bool input(int x, int y);
//void dfs(int x, int y, int cnt);

int main(void)
{
    //M가로의 개수, N세로의 개수
    scanf("%d %d", &M, &N);
    map.assign(N,vector<int>(M,0));
    //answer.assign(N,vector<int>(M,-1));
    //s_visted.assign(N,vector<bool>(M,false));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            scanf("%d", &map[i][j]);
            //if(map[i][j] == -1) answer[i][j] == -1;
            if(map[i][j]==1)
            {                
                //maketo.push_back(pair<int,int>(i,j));
                //is_visted[i][j]=true; 
                one.push(pair<int,int>(i,j));
            }
            //if(map[i][j]==-1) is_visted[i][j]=true; 
        }
    }
    /*for(int i=0;i<maketo.size();i++)
    {
        dfs(maketo[i].second,maketo[i].first,0);
    }*/
    bool is_end=true;
    long long now = 0;
    queue<pair<int,int>> empty;
    tmp_q=empty;
    while(is_end)
    {
        while(!one.empty())
        {
            int x = one.front().second;
            int y = one.front().first;
            one.pop();
            
            //answer[y][x] = now;
            if(input(x+1,y)) {tmp_q.push(pair<int,int>(y,x+1)); map[y][x+1]=1;}
            if(input(x-1,y)) {tmp_q.push(pair<int,int>(y,x-1)); map[y][x-1]=1;}
            if(input(x,y+1)) {tmp_q.push(pair<int,int>(y+1,x)); map[y+1][x]=1;}
            if(input(x,y-1)) {tmp_q.push(pair<int,int>(y-1,x)); map[y-1][x]=1;}
        }
        /*for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            printf("%2d ", map[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");*/
        
        if(tmp_q.empty()) break;
        one = tmp_q;
        /*if(!tmp_q.empty())
        {
            while(!tmp_q.empty())
            {
            printf("%d %d\n", tmp_q.front().first, tmp_q.front().second);
            tmp_q.pop();
            }
            printf("\n\n");
        }*/
        //one = tmp_q;
        tmp_q =  empty;
        now++;
    }
    //dfs(maketo[0].second,maketo[0].first,0);

    bool is_ok =true;
    int min = 0;
    for(int i=0;i<N;i++)
    {
        if(is_ok==false) break;
        for(int j=0;j<M;j++)
        {
            if(map[i][j]==0) {
                is_ok=false;
                break;
            }
            /*if(answer[i][j]==-1)
            {
                if(map[i][j]==0){
                    is_ok=false;
                    break;
                }                
            }
            else
            {
                if(min < answer[i][j]) min = answer[i][j];
            }*/
        }
    }
    /*for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            printf("%2d ", answer[i][j]);
        }
        printf("\n");
    }*/
    if(is_ok) printf("%d\n", now);
    else printf("%d\n",-1);
    return 0;
}
/*void dfs(int x, int y, int cnt)
{
    if(x<0 || y<0 || x>=M || y>=N) return;
    if(map[y][x] == -1 ) return;
    if(map[y][x] == 1 && cnt != 0) cnt=0;
    if(answer[y][x]==-1) answer[y][x]=cnt;
    else{
        if (answer[y][x] > cnt) answer[y][x]=cnt;
        else return;
    }
    dfs(x+1,y,cnt+1);
    dfs(x-1,y,cnt+1);
    dfs(x,y-1,cnt+1);
    dfs(x,y+1,cnt+1);  
}*/
/*void bfs(int x, int y, int cnt)
{
    if(x<0 || y<0 || x>=M || y>=N) return;
    if(is_visted[y][x]) return;
    is_visted[y][x]=true;
    
}*/
bool input(int x, int y)
{
    if(x<0 || y<0 || x>=M || y>=N) return false;
    if(map[y][x] == 0 ) return true;
    return false;
    //if(map[y][x] == -1 ) {return false; }
    /*if(map[y][x] == 1 || map[y][x] == -1) return false;
    return true;*/
}
