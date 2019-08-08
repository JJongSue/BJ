#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
static int N, M;
vector<string> pq;
vector<int> pqi;
void find_num(int cnt, int now,string str);
int main(void)
{
    
    scanf("%d %d", &N, &M);    
    for(int i=0;i<N;i++)
    {
        int tmp=0;
        scanf("%d", &tmp);        
        bool is = true;
        for(int j=0;j<pqi.size();j++)
        {
            if(tmp == pqi[j]) {
                is=false;
                break;
            }
        }
        if(is==true) pqi.push_back(tmp);

    }
    sort(pqi.begin(), pqi.end());    
    find_num(0,0,"");
    /*sort(pq.begin(), pq.end());
    cout << pq.at(0) << endl;
    for(int i=1;i<pq.size();i++)
    {
        if(pq.at(i) != pq.at(i-1))
        {
            cout << pq.at(i) << endl;
            
        }
        
    }*/
    return 0;
}
void find_num(int cnt, int now,string str)
{
    if(cnt ==M)
    {
        //pq.push_back(str);
        cout << str << endl;
        return;
    }
    if(now == pqi.size()) return;    
    string str2 = str+to_string(pqi[now])+" ";
    find_num(cnt+1, now+1, str2);
    find_num(cnt, now+1, str);
    
    
    

    return;
}