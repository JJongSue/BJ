#include<iostream>
#include<queue>
#include<vector>
using namespace std;
static vector<int> lot;
static int N;
void find_num(queue<int> q,int now);
int main(void)
{
    //입력이 들어오면 break로 종료
    bool is_end = true;
    queue<int> que;
    while(true)
    {
        scanf("%d", &N);
        if(N==0) break;
        lot.assign(N,0);
        for(int i=0;i<N;i++) scanf("%d", &lot[i]);
        find_num(que, 0);
        printf("\n");
        
    }
    return 0;
}
void find_num(queue<int> q,int now)
{
    if(q.size() == 6)
    {
        for(int i=0;i<6;i++)
        {
            printf("%d ", q.front());
            q.pop();
        }
        printf("\n");
        return;
    }
    if(now == N) return;
    queue<int> copy = q;
    copy.push(lot[now]);
    find_num(copy, now+1);
    copy=q;
    find_num(copy, now+1);
}