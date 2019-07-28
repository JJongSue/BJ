#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int N = 0, C = 0;
    
    scanf("%d %d", &N, &C);
    vector<bool> is_ok(C, false);
    vector<int> fire(N, 0);
     
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &fire[i]);
    }
    for (int i = 0; i < C; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if ((i + 1) % fire[j] == 0)
            {
                is_ok[i] = true;
                break;
            }
        }
    }
    int answer = 0;
    for (int i = 0; i < C; i++)
    {
        if (is_ok[i])
            answer++;
    }
    printf("%d", answer);

    return 0;
}