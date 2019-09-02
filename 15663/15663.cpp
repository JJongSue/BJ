#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
static int N, M;
static vector<int> arr;
static vector<int> ans;
static vector<int> pos;
static vector<bool> visited;
void printans(int now, int cnt);
int main(void)
{
    scanf("%d %d", &N, &M);
    for(int i=0;i<N;i++)
    {
        int tmp;
        bool ok = true;
        scanf("%d", &tmp);
        /*for(int j=0;j<arr.size();j++)
        {
            if(arr[j] == tmp)
            {
                ok=false;
                break;
            }
        }*/
       // if(ok)
        //{
            arr.push_back(tmp);
        //}
    }
    sort(arr.begin(), arr.end());
    ans.assign(M, 0);
    pos.assign(M,-1);
    visited.assign(M,false);
    printans(0,0);
    return 0;

    

}
void printans(int now, int cnt)
{
    if(cnt == M)
    {
        bool same = true;
        for(int i=0;i<M;i++)
        {
            if(ans[i] != pos[i])
            {
                same = false;
                break;
            }                
        }
        if(!same)
        {
            for(int i=0;i<M;i++)
        {
            printf("%d ", ans[i]);
            pos[i] = ans[i];
        }
        printf("\n");
        }
        
        return;
    }
    if(now == arr.size()) return;
    for(int i=0;i<arr.size();i++)
    {
        if((i>0 && arr[i]!=arr[i-1]) || i==0)
        if(!visited[i])
        {
            visited[i]=true;
            ans[cnt] = arr[i];
            printans(i, cnt+1);
            visited[i]=false;
        }
        
    }
}