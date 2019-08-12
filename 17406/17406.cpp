#include<iostream>
#include<vector>
#include<queue>
using namespace std;
static vector<vector<int>> real_map;
static vector<vector<int>> map;
static vector<vector<int>> rota;
static int N, M, K;
static int ans = 10e8;
void find_ans(vector<int> a);
void solve(vector<int> a, int size);

int main(void)
{
    //input
    //N 세로 M 가로 K 회전수
    //배열
    //r c s K개 가장 위쪽칸 r-s c-s 가장 오른쪽 아랫칸 r+s c+s
    //이를 회전
    
    scanf("%d %d %d", &N, &M, &K);
    real_map.assign(N, vector<int>(M,0));
    //vector<vector<int>> copy_map(N, vector<int>(M,0));
    rota.assign(K, vector<int>(3,0));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
            scanf(" %d", &real_map[i][j]);
    }
    for(int i=0;i<K;i++)
    {
        for(int j=0;j<3;j++) scanf(" %d", &rota[i][j]);
    }
    /*for(int i=0;i<K;i++)
    {
        vector<int> a(1,i);
        solve(a, 1);
    }*/
    vector<int> a;
    solve(a, 0);
    printf("%d\n", ans);

    
    return 0;
}
void solve(vector<int> a, int size){
    if(a.size() == K){
        find_ans(a);
    }
    else{
        for(int i=0;i<K;i++){
            bool swit=true;
            for(int j=0;j<a.size();j++)
            {
                if(a[j] == i){
                    swit=false;
                    break;
                }                
            }
            if(swit){
                    vector<int> b=a;
                    //b = a;
                    b.push_back(i);
                    solve(b, size+1);
                }
        }
    }
}
void find_ans(vector<int> a){
    map=real_map;
    for(int cal=0;cal<K;cal++)
    {
        int i = a[cal];
        //printf("%d\n", i);
        int r=rota[i][0], c=rota[i][1], s=rota[i][2];
        //printf("%d %d %d\n", r, c ,s);
        int in=0;
        vector<vector<int>> copy_map=map;
        
        while(true)
        {
            if (in >= s )
                break;
            for(int j = c-s-1+in;j<c+s-1-in;j++)
            {
                map[r-s-1+in][j+1] = copy_map[r-s-1+in][j];
            }
            for (int j = r-s-1+in; j < r +s-1-in; j++)
            {
                map[j+1][c+s-1-in] = copy_map[j][c+s-1-in];
            }
            for (int j = c+s-1-in; j > c-s-1+in; j--)
            {
                map[r+s-1-in][j-1] = copy_map[r+s-1-in][j];
            }
            for (int j = r+s-1-in; j > r-s-1+in; j--)
            {
                map[j-1][c-s-1+in] = copy_map[j][c-s-1+in];
            }            
            in++;
            /*for(int js=0;js<N;js++)
            {
                for(int cs=0;cs<M;cs++)
                {
                    printf("%d ", map[js][cs]);
                }
                printf("\n");
            }
            printf("\n\n");*/
        }
        
    }
    int sum=0;
        for(int j=0;j<N;j++)
        {
            sum=0;
            for(int k=0;k<M;k++)
            {
                sum+=map[j][k];
            }
            if(ans > sum) ans = sum;
        }

    
}