#include<iostream>
#include<vector>
using namespace std;

static vector<vector<char>> map;
static vector<vector<bool>> is_visitmap;
static vector<bool> is_visitpro;
static vector<vector<int>> distance;
static vector<pair<int,int>> product;
static int N, M, P;
static int ans;
int main(void){
    scanf("%d %d", &N, &M);
    pair<int, int> start;
    product.clear();
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            scanf("%c", &map[i][j]);
            if(map[i][j]=='S') start=pair<int,int>(j,i);
            if(map[i][j]=='X') product.push_back(pair<int,int>(j,i));
        }
    }
    P = product.size();
    return 0;
}
void find_dis(int x, int y, )
{

}