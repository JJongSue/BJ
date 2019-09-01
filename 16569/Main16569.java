package boj16569;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main16569 {
	static final int dx[] = {0,-1,1,0};
	static final int dy[] = {-1,0,0,1};
	
	// 높이를 나타내는 map
	static int[][] map;
	// 세로 가로 화산수
	static int N, M, K;
	// 화산을 담는 큐
	static Queue<vol> que;
	// 재상이의 현재 위치
	static int p_x, p_y;
	//재상의 bfs를 위한 que
	static Queue<vol> manQ;
	// 최고높이와 최단시간
	static int ans_h, ans_time;
	//가장 최고 높이
	static int map_max;

	// 화산
	static class vol {
		int x;
		int y;
		int t;

		public vol(int x, int y, int t) {
			super();
			this.x = x;
			this.y = y;
			this.t = t;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		// 가로 세로 화산의수 받음
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());

		// 재상의 위치 input
		st = new StringTokenizer(br.readLine());
		p_y = Integer.parseInt(st.nextToken())-1;
		p_x = Integer.parseInt(st.nextToken())-1;
		manQ = new LinkedList<Main16569.vol>();
		manQ.add(new vol(p_x, p_y, 0));

		map_max=0;
		// map과 화산que를 선언후 입력받음
		map = new int[N][M];
		que = new LinkedList<vol>();
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if(map[i][j] > map_max) map_max = map[i][j]; 
				
			}
		}
		for (int i = 0; i < K; i++) {
			st = new StringTokenizer(br.readLine());
			int y = Integer.parseInt(st.nextToken())-1;
			int x = Integer.parseInt(st.nextToken())-1;
			int t = Integer.parseInt(st.nextToken());
			map[y][x] =-1;
			que.add(new vol(x, y, t));
		}

		ans_h = map[p_y][p_x];
		map[p_y][p_x]=-1;
		ans_time = 0;
		go();
		System.out.println(ans_h + " "+ ans_time);
	}
	static void go()
	{
		int time = 1;
		while(!manQ.isEmpty())
		{
			Queue<vol> tmpVQ = new LinkedList<Main16569.vol>();
			Queue<vol> tmpMQ = new LinkedList<Main16569.vol>();
			
			while(!que.isEmpty())
			{
				vol tmp = que.poll();
				
				/*if(tmp.t == time)
				{
					boom(tmp.x, tmp.y, time);
					continue;
				}*/
				if(tmp.t < time)
				boom(tmp.x,tmp.y,time-tmp.t);
				tmpVQ.add(tmp);
			}
			
			while(!manQ.isEmpty())
			{
				vol tmp = manQ.poll();
				for(int i=0;i<4;i++)
				{
					int xx = tmp.x+dx[i];
					int yy = tmp.y+dy[i];
					if(is_map(xx,yy))
					{
						vol nv = new vol(xx,yy, time);
						if(ans_h < map[yy][xx])
						{
							ans_h = map[yy][xx];
							ans_time = time;
							if(ans_h == map_max) return;
						}
						map[yy][xx]=-1;
						tmpMQ.add(nv);
					}
				}
				
			}
			
			
			
			
			
			
			/*System.out.println(time);
			for(int i=0;i<N;i++)
			{
				for(int j=0;j<M;j++)
				{
					System.out.printf("%2d ",map[i][j]);
				}System.out.println();
			}System.out.println("\n\n");*/
			manQ.addAll(tmpMQ);
			que.addAll(tmpVQ);
			time++;
			
		}
	}
	

	// 화산 폭발 메소드
	static void boom(int x, int y, int time) {
		for (int i = y; i <= y+time; i++) {
			for (int j = x - (y + time - i); j <= x + (y + time - i); j++) {
				if (is_map(j, i)) {
					map[i][j]=-1;
				}
			}
		}
		for (int i = y-1; i >= y-time; i--) {
			for (int j = x - (-y + time + i); j <= x + (-y + time + i); j++) {
				if (is_map(j, i)) {
					map[i][j]=-1;
				}
			}
		}
		/*System.out.println(x+" "+y);
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)
			{
				System.out.printf("%2d ",map[i][j]);
			}System.out.println();
		}System.out.println("\n\n");*/
	}
	

	// 맵인지 확인하는 매소드 맵 범위
	// 안쪽 일경우 true
	// 아닐 경우 false를 리턴
	static boolean is_map(int x, int y) {
		if (x < 0 || y < 0 || x >= M || y >= N)
			return false;
		if(map[y][x]==-1) return false;

		return true;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

}
