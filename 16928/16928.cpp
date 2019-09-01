#include <iostream>
#include <vector>
using namespace std;
static int map[101] = {
    0,
};
static int min_map[101] = {
    0,
};

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < 101; i++)
    {
        map[i] = i;
        min_map[i] = 1000;
    }

    for (int i = 0; i < N; i++)
    {
        int a;
        scanf("%d", &a);
        scanf("%d", &map[a]);
        min_map[a] = 1000;
    }
    for (int i = 0; i < M; i++)
    {
        int a;
        scanf("%d", &a);
        scanf("%d", &map[a]);
        min_map[a] = 1000;
    }
    min_map[100] = 0;
    /*for(int i=1;i<=100;i++)
    {
        printf("%d ", min_map[i]);
        //printf("%d ", min_map[i]);
        if(i%10==0) printf("\n");
    }*/
    for (int i = 99; i > 0; i--)
    {

        //if(min_map[i]==-1) break;
        if (map[i] < i)
            continue;
        if (map[i] > i)
        {
            int tmp = map[i];
            min_map[i] = min_map[tmp];
            continue;
        }
        for (int j = 1; j < 7; j++)
        {
            if (i + j > 100)
                break;
            int tmp = i + j;
            if (min_map[i] > min_map[tmp] + 1)
                min_map[i] = min_map[tmp] + 1;
        }
    }
    for (int i = 99; i > 0; i--)
    {
        if (min_map[i] == 1000)
        {
            int tmp = i;
            /*while (true)
            {
                if (tmp == map[tmp])
                    break;
                tmp = map[tmp];
            }*/
            min_map[i] = min_map[map[i]];
        }
    }
    for (int i = 99; i > 0; i--)
    {
        if (map[i] == i)
        {
            for (int j = 1; j < 7; j++)
            {
                if (i + j > 100)
                    break;
                int tmp = i + j;
                if (min_map[i] > min_map[tmp] + 1)
                    min_map[i] = min_map[tmp] + 1;
            }
        }
        else{
            min_map[i]=min_map[map[i]];
        }
    }
    for (int i = 99; i > 0; i--)
    {
        if (map[i] == i)
        {
            for (int j = 1; j < 7; j++)
            {
                if (i + j > 100)
                    break;
                int tmp = i + j;
                if (min_map[i] > min_map[tmp] + 1)
                    min_map[i] = min_map[tmp] + 1;
            }
        }
        else{
            min_map[i]=min_map[map[i]];
        }
    }
    /*for(int i=1;i<=100;i++)
    {
        //printf("%d ", map[i]);
        printf("%d ", min_map[i]);
        if(i%10==0) printf("\n");
    }*/
    printf("%d\n", min_map[1]);
    return 0;
}