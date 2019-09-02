package boj17135;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main17135 {
		static int N, M, D;
		static int []archer = new int[3];
		static boolean [][][]map;
		static int ans;
		static Queue<pair> q = new LinkedList<pair>();
		static class pair{
			int x;
			int y;
			public pair(int x, int y) {
				super();
				this.x = x;
				this.y = y;
			}
			
		}
		public static void main(String[] args) {
			Scanner sc = new Scanner(System.in);
			N = sc.nextInt();
			M = sc.nextInt();
			D = sc.nextInt();
			ans=0;
			map = new boolean[N][M][2];
			for(int i=0;i<N;i++)
			{
				for(int j=0;j<M;j++)
				{
					int tmp = sc.nextInt();
					if(tmp == 1) map[i][j][0]=true;
				}
			}
			set_arc(0, 0);
			System.out.println(ans);
			
		}
		static void set_arc(int now, int cnt)
		{
			if(cnt == 3)
			{
				int first = do_game();
				if(ans < first) ans = first;
				return;
			}
			if(now == M) return;
			//System.out.println(now+" "+cnt);
			archer[cnt]= now;
			set_arc(now+1, cnt+1);
			set_arc(now+1, cnt);
			
			
		}
		static int do_game()
		{
			q = new LinkedList<pair>();
			int cnt=0;
			boolean [][][] map2 = new boolean[N][M][2];
			for(int i=0;i<N;i++)
			{
				for(int j=0;j<M;j++)
				{
					System.arraycopy(map[i][j], 0, map2[i][j], 0, 2);
				}
			}
			while(!clean_map())
			{
				
				for(int i=0;i<3;i++)
				{

					boolean is_shoot=false;
					for(int j=1;j<=D;j++)
					{
						if(is_shoot) break;
						for(int k=archer[i]-j+1;k<=archer[i];k++)
						{
							int y = N-1-k+archer[i]+1-j;
							if(is_map(k, y))
							{
								if(map[y][k][0])
								{
									if(!map[y][k][1])
									{
										map[y][k][1] =true;
										cnt++;
										q.add(new pair(k, y));
									}
										is_shoot = true;
										break;
									
								}
							}							
						}
						if(is_shoot) break;
						for(int k=archer[i]+1;k<=archer[i]+j-1;k++)
						{
							int y = N-1+k-archer[i]+1-j;
							if(is_map(k, y))
							{
								if(map[y][k][0])
								{
									if(!map[y][k][1])
									{
										map[y][k][1] =true;
										q.add(new pair(k, y));
										cnt++;
									}
										is_shoot = true;
										break;									
								}
							}							
						}
					}					
				}
				while(!q.isEmpty())
				{
					pair tmp = q.poll();
					map[tmp.y][tmp.x][0]=false;
					map[tmp.y][tmp.x][1]=false;
				}
				for(int i=N-1;i>=1;i--)
				{
					for(int j=0;j<M;j++)
					{
						map[i][j][0]=map[i-1][j][0];
						map[i][j][1]=map[i-1][j][1];
					}
				}
				for(int i=0;i<M;i++) {
					map[0][i][0]=false;
					map[0][i][1]=false;
				}
				
				/*for(int i=0;i<N;i++)
				{
					for(int j=0;j<M;j++)
					{
						if(map[i][j][0]) System.out.print(1+" ");
						else System.out.print(0+" ");
					}System.out.println();
				}System.out.println(cnt+"\n");*/
				
				
			}
			for(int i=0;i<N;i++)
			{
				for(int j=0;j<M;j++)
				{
					System.arraycopy(map2[i][j], 0, map[i][j], 0, 2);
				}
			}
			
			
			return cnt;
		}
		static boolean clean_map()
		{
			for(int i=0;i<N;i++)
			{
				for(int j=0;j<M;j++)
				{
					if(map[i][j][0]) return false;
				}
			}
			return true;
		}
		static boolean is_map(int x, int y)
		{
			if(x<0 || y<0 || x>=M || y>=N) return false;
			return true;
		}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
}
