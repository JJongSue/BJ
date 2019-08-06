#include <iostream>
#include<string>
using namespace std;
int main(void)
{
    string y,x;
    cin >> x >> y;
    int im=y.length(), jm=x.length();
    int findx=0,findy=0;
    bool is_end=false;
    for(int i=0;i<jm;i++)
    {
        if(is_end) break;
        for(int j=0;j<im;j++)
        {
            if(y[j] == x[i])
            {
                findy=j;
                findx=i;
                is_end=true;
                break;
            }
        }
    }
    for(int i=0;i<im;i++)
    {
        for(int j=0;j<jm;j++)
        {
            if(i==findy) {
                cout << x;
                break;
            }
            if(j==findx){
                printf("%c", y[i]);
                continue;             
            }
            printf(".");
        }
        printf("\n");
    }
    return 0;
}