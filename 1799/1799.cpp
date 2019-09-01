#include<iostream>
#include<vector>
#include <queue>
using namespace std;

static int leftans,rightans, N;
static vector<vector<int>> map;

bool is_map(int x, int y);
void find_ans(int now, int sum);
void find_ans1(int now, int sum);
int main()
{
	leftans = 0, rightans=0;
	scanf("%d", &N);
	map.assign(N, vector<int>(N, 0));
	int max = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf(" %d", &map[i][j]);

		}
	}
	/*for (int j = 0; j < N; j++)
	{
        //printf("%d\n", j);
		int ur = 0, ul = 0, dl = 0, dr = 0;
		for (int i = 0; i < N; i++)
		{
			if (j + i < N && map[i][j+i] != 0) {
				ur++;
			}
			if (j - i >= 0 && map[i][j-i] != 0) {
				ul++;
			}
			if (j + i < N && map[N - 1 - i][j+i] != 0) {
				dr++;
			}
			if (j - i >= 0 && map[N - 1 - i][j-i] != 0) {
				dl++;
			}
            
		}*/
       /* for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%2d ", map[i][j]);
        }printf("\n");
    }*/

        //printf("1 %d ur:%d ul:%d dr:%d dl:%d\n\n\n", j, ur, ul, dr, dl);
		/*for (int i = 0; i < N; i++)
		{
			if (j + i < N && map[i][i+j] != 0 && j!=0) {
				map[i][j+i] += (ur - 1);
			}
			if (j - i >= 0 && map[i][j-i] != 0) {
				map[i][j-i] += (ul - 1);
			}
			if (j + i < N && map[N - 1 - i][i+j] != 0 && j!=0) {
				map[N - 1 - i][j+i] += (dr-1);
			}
			if (j - i >= 0 && map[N-1-i][j-i] != 0 ) {
				map[N - 1 - i][j-i] += (dl-1);
			}
		}
        //printf("2 %d\n", j);
	}*/
    /*for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%2d ", map[i][j]);
        }printf("\n");
    }*/
	int sum=0;
	/*for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(map[i][j] == 1)
			{
				map[i][j] = 0;
				sum++;
			}
		}
	}*/
	if(N==1){
		if(map[0][0]==1) printf("1\n");
		else printf("0\n");
	}
	else if(N==2){
		int x=0;
		if(map[0][0]==1 || map[1][1] ==1) x=1;
		int y=0;
		if(map[0][1]==1 || map[1][0] == 1) y=1;
		printf("%d\n", x+y);
	}
	else{
		find_ans(0,0);
	find_ans1(1,0);
	printf("%d\n", leftans+rightans);
	}
	

	
	/*
	bool is_end = false;
	while (!is_end)
	{
		int sum = 0;
		queue<pair<int, int>> empty_q, que;
		for (int i = 0; i < N; i++)
		{
			if (sum == -1) break;
			for (int j = 0; j < N; j++)
			{
				if (sum == -1) break;
				if (map[i][j] == 1) sum++;
				if (map[i][j] > 1) sum = -1;
			}				
		}
		if (sum != -1) break;
		int max = 1;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (max < map[i][j])
				{
					max = map[i][j];
					que = empty_q;
					que.push(pair<int, int>(j, i));
				}
				else if (max == map[i][j])
				{
					que.push(pair<int, int>(j, i));
				}
			}
		}
        if(max == 2) break;
		while (!que.empty())
		{
			int x = que.front().first;
			int y = que.front().second;
			que.pop();
			for (int i = 1; i < N; i++)
			{
				if (x - i >= 0 && y - i >= 0 && map[y - i][x - i] > 0) {
					map[y - i][x - i]--;
				}
				if (x + i < N && y - i >= 0 && map[y - i][x + i] > 0) {
					map[y - i][x + i]--;
				}
				if (x - i >= 0 && y + i < N && map[y + i][x - i] > 0) {
					map[y + i][x - i]--;
				}
				if (x + i < N && y + i < N && map[y + i][x + i] > 0) {
					map[y + i][x + i]--;
				}
				map[y][x] = 0;
			}
		}
	}int dap = 0;
    int two = 0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(map[i][j] == 1) dap++;
            if(map[i][j] == 2) two++;
        }
    }*/


	//printf("%d\n", dap+two/2);

}
void find_ans(int now, int sum)
{
	if(now>=N*N)
	{
		if(leftans < sum) leftans = sum;
		return;
	}
	if(map[now/N][now%N]==0){
		if(N%2==1) find_ans(now+2, sum);
		else {
			if(now%N==N-1) find_ans(now+1,sum);
			else if(now%N==N-2) find_ans(now+3,sum);
			else find_ans(now+2, sum);
		}
		return;
	}
	vector<vector<int>> copymap = map;
	for(int j=now%N;j<N;j++)
	{
		int i=j-now%N;
		if(is_map(j,now/N+i)) map[now/N+i][j]=0;
		//if(is_map(j,now/N-i)) map[now/N-i][j]=0;
	}
	for(int j=now%N;j>=0;j--)
	{
		int i=now%N-j;
		if(is_map(j,now/N+i)) map[now/N+i][j]=0;
		//if(is_map(j,now/N-i)) map[now/N-i][j]=0;
	}
	if(N%2==1) find_ans(now+2, sum+1);
		else {
			if(now%N==N-1) find_ans(now+1,sum+1);
			else if(now%N==N-2) find_ans(now+3,sum+1);
			else find_ans(now+2, sum+1);
		}
	map=copymap;
	if(N%2==1) find_ans(now+2, sum);
		else {
			if(now%N==N-1) find_ans(now+1,sum);
			else if(now%N==N-2) find_ans(now+3,sum);
			else find_ans(now+2, sum);
		}

}
void find_ans1(int now, int sum)
{
	if(now>=N*N)
	{
		if(rightans < sum) rightans = sum;
		return;
	}
	if(map[now/N][now%N]==0){
		if(N%2==1) find_ans1(now+2, sum);
		else {
			if(now%N==N-1) find_ans1(now+1,sum);
			else if(now%N==N-2) find_ans1(now+3,sum);
			else find_ans1(now+2, sum);
		}
		return;
	}
	vector<vector<int>> copymap = map;
	for(int j=now%N;j<N;j++)
	{
		int i=j-now%N;
		if(is_map(j,now/N+i)) map[now/N+i][j]=0;
		if(is_map(j,now/N-i)) map[now/N-i][j]=0;
	}
	for(int j=now%N;j>=0;j--)
	{
		int i=now%N-j;
		if(is_map(j,now/N+i)) map[now/N+i][j]=0;
		if(is_map(j,now/N-i)) map[now/N-i][j]=0;
	}
	if(N%2==1) find_ans1(now+2, sum+1);
		else {
			if(now%N==N-1) find_ans1(now+1,sum+1);
			else if(now%N==N-2) find_ans1(now+3,sum+1);
			else find_ans1(now+2, sum+1);
		}
	map=copymap;
	if(N%2==1) find_ans1(now+2, sum);
		else {
			if(now%N==N-1) find_ans1(now+1,sum);
			else if(now%N==N-2) find_ans1(now+3,sum);
			else find_ans1(now+2, sum);
		}

}
bool is_map(int x, int y)
{
	if(x<0 || y<0 || x>=N || y>=N) return false;
	if(map[y][x]==0) return false;
	return true;
}