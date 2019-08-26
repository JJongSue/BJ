#include<iostream>
#include<vector>
#include <queue>
using namespace std;


int main()
{
	int N, ans=0;
	vector<vector<int>> map;
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
	for (int j = 0; j < N; j++)
	{
		int ur = 0, ul = 0, dl = 0, dr = 0;
		for (int i = 0; i < N; i++)
		{
			if (j + i < N && map[i][j+1] != 0) {
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
            
		}

		for (int i = 0; i < N; i++)
		{
			if (j + i < N && map[i][j] != 0) {
				map[i][j+i] += (ur - 1);
			}
			if (j - i >= 0 && map[i][j] != 0) {
				map[i][j-i] += (ul - 1);
			}
			if (j + i < N && map[N - 1 + i][j] != 0) {
				map[N - 1 - i][j] += (dr-1);
			}
			if (j - i >= 0 && map[i][j] != 0) {
				map[N - 1 - i][j-i] += (dl-1);
			}
		}
	}
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%2d ", map[i][j]);
        }printf("\n");
    }
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
        if(max == 1) break;
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
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(map[i][j] == 1) dap++;
        }
    }


	printf("%d\n", dap);

}
