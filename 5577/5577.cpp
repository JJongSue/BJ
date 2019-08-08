#include<iostream>
#include<vector>
using namespace std;
//품
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
            bool is_end = true;
            int now_N=N;
            int cnt=1;
            int now_color = j;
            int up=i-1;
            int down=i+1;
            
            while(is_end)
            {
                //if((tmp[up] != tmp[down])) break;// || up < 0 || down >= N) break;
                if(up+1 == down-1) {cnt=1; now_color=j;}
                else {cnt=0; now_color=tmp[up];}
                                
                
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
                else is_end=false;
            }
            if(min > now_N)  min = now_N;
            

        }
    }
    printf("%d\n", min);

    return 0;
}