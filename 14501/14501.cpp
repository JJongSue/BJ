#include<iostream>
#include<vector>
using namespace std;
static int N, ans = -1;
static vector<pair<int,int>> day;
void find_max(int now, int sum);
int main(void)
{
    //N 1~N까지 일하고 N+1날 퇴사
    scanf("%d", &N);
    //pair<int,int>를 가지는 vector day first:걸리는 시간 second 수익
    day.assign(N, pair<int,int>(0,0));
    for(int i=0;i<N;i++)
    {
        scanf("%d %d", &day[i].first, &day[i].second);
    }
    find_max(0,0);
    printf("%d\n", ans);
}
void find_max(int now, int sum)
{
    if(now >= N)
    {
        if(sum > ans) ans = sum;
        return;
    }
    if(now+day[now].first <= N)
    {
        find_max(now+day[now].first, sum+day[now].second);
    }
    find_max(now+1, sum);

}