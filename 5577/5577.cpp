#include<iostream>
#include<vector>
using namespace std;
//못품
int main(void)
{
    int N=0;    
    scanf("%d", &N);
    vector<int> pang(N,0);
    for(int i=0;i<N;i++) scanf("%d", &pang[i]);
    vector<int> tmp = pang;    
    int min=10000;
    for(int i=0;i<N;i++)
    {
        for(int j=1;j<=3;j++)
        {
            tmp=pang;
            tmp[i]=j;
            bool is_end = true;
            int now_N=N;
            int cnt=1;
            int now_color = j;
            int up=j-1;
            int down=j+1;
            while(is_end)
            {
                while(up >= 0)
                {
                    if(tmp[up]==now_color)
                    {
                        cnt++;
                        up--;
                    }
                    else{
                        break;
                    }
                }
                while(down<N)
                {
                    if(tmp[down] == now_color)
                    {
                        cnt++;
                        down++;
                    }
                    else{
                        break;
                    }
                }
                if(cnt>=4)
                {
                    now_N-=cnt;
                }
                if(left )

                

            }
            

        }
    }

    return 0;
}