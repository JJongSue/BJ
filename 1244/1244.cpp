#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    vector<int> a;//(N,0);
    /* int a[5][20] = {
        0,
    };*/
    
    for (int i = 0; i < N; i++)
    {
        int tmp = 0;
        scanf("%d", &tmp);
        a.push_back(tmp);
        //scanf(" %d", &a[i]);
    }

    int asdf = 0;
    scanf("%d", &asdf);
    int gen = 0, num = 0;
    for (int i = 0; i < asdf; i++)
    {
        scanf("%d %d", &gen, &num);
        if (gen == 1)
        {
            int x = num;
            int count = 1;
            while (x <= N)
            {
                a[x-1] = a[x-1]^1;
                count++;
                x = num * count;
            }
        }
        else if (gen == 2)
        {
            int ax = num-1;
            int iter =1;
            a[num-1] = a[num-1] ^ 1;
            while(1)    
            {
                if(ax-iter < 0 || ax+iter >= N)
                {
                    break;
                }
                else{
                    if(a[ax-iter] == a[ax+iter])
                    {
                        
                        
                        a[ax-iter] = a[ax-iter]^1;
                        a[ax+iter] = a[ax+iter]^1;
                        iter++;
                    }
                    else break;
                }
            }
        }
    }

    for (int s = 0; s < N; s++)
    {
        printf("%d ", a[s]);
        if( s % 20== 19 ) printf("\n");
    }
        
}