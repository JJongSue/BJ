#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    int testcase_num = 0;
    scanf("%d", &testcase_num);
    for(int testcase_i = 1; testcase_i<=testcase_num;testcase_i++)
    {
        int N=0;
        scanf("%d", &N);
        vector<int> a (N, 0);
        for(int i=0;i<N;i++)
        {
            scanf("%d", &a[i]);
        }
    }
    return 0;
}