package boj13460;

import java.util.Scanner;

public class Main13460 {
	final static int dx[] = {0,-1,1,0};
	final static int dy[] = {-1,0,0,1};
	static boolean red_die=false, blue_die=false;
	static char [][]map;
	static int N, M;
	static int ans=11;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		map = new char[N][M];
		sc.nextLine();
		for(int i=0;i<N;i++)
		{
			String tmp = sc.nextLine();
			for(int j=0;j<M;j++)
			{
				map[i][j] = tmp.charAt(j);
			}
		}
		/*left();
		down();
		right();
		down();
		left();*/
		//look_map();
		/*right();
		down();
		System.out.println(red_die + " " +blue_die);
		look_map();*/
		
		do_game(1, -1);
		if(ans == 11) System.out.println(-1);
		else System.out.println(ans);
		/*down();
		look_map();
		up();
		look_map();*/
		
	}
	
	static void do_game(int now, int post)
	{
		if(now == 11) return;
		if(now > ans) return;
		char [][]copy_map = new char[N][M];
		for(int i=0;i<N;i++)
		{
			System.arraycopy(map[i], 0, copy_map[i], 0, M);
		}
		
		if(post != 0) {
			left();
			if(blue_die) {
				blue_die = false;
				red_die = false;
				for(int i=0;i<N;i++)
				{
					System.arraycopy(copy_map[i], 0, map[i], 0, M);
				}				
			}
			else if(red_die) {
				red_die=false;
				if(now < ans) {
					ans = now;
				}
				for(int i=0;i<N;i++)
				{
					System.arraycopy(copy_map[i], 0, map[i], 0, M);
				}
			}
			else {
				do_game(now+1, 0);
				for(int i=0;i<N;i++)
				{
					System.arraycopy(copy_map[i], 0, map[i], 0, M);
				}
			}
			
		}

		if(post != 1) {
			right();
			if(blue_die) {
				blue_die = false;
				red_die = false;
				for(int i=0;i<N;i++)
				{
					System.arraycopy(copy_map[i], 0, map[i], 0, M);
				}

			}
			if(red_die) {
				red_die=false;
				if(now < ans) {
					ans = now;
				}
				for(int i=0;i<N;i++)
				{
					System.arraycopy(copy_map[i], 0, map[i], 0, M);
				}

			}
			else {
				do_game(now+1, 1);
				for(int i=0;i<N;i++)
				{
					System.arraycopy(copy_map[i], 0, map[i], 0, M);
				}
			}
		}
		

		if(post != 2) {
			up();
			if(blue_die) {
				blue_die = false;
				red_die = false;
				for(int i=0;i<N;i++)
				{
					System.arraycopy(copy_map[i], 0, map[i], 0, M);
				}

			}
			if(red_die) {
				red_die=false;
				if(now < ans) {
					ans = now;
				}
				for(int i=0;i<N;i++)
				{
					System.arraycopy(copy_map[i], 0, map[i], 0, M);
				}

			}
			else {
				do_game(now+1, 2);
				for(int i=0;i<N;i++)
				{
					System.arraycopy(copy_map[i], 0, map[i], 0, M);
				}
			}
		}
		
		
		if(post != 3) {
			down();
			if(blue_die) {
				blue_die = false;
				red_die = false;
				for(int i=0;i<N;i++)
				{
					System.arraycopy(copy_map[i], 0, map[i], 0, M);
				}

			}
			if(red_die) {
				red_die=false;
				if(now < ans) {
					ans = now;
				}
				for(int i=0;i<N;i++)
				{
					System.arraycopy(copy_map[i], 0, map[i], 0, M);
				}

			}
			else {
				do_game(now+1, 3);
				for(int i=0;i<N;i++)
				{
					System.arraycopy(copy_map[i], 0, map[i], 0, M);
				}
			}
		}
		
		
		
	}
	static void left()
	{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M-1;j++)
			{
				if(map[i][j] == '#' || map[i][j] == 'R' || map[i][j] == 'B') continue;
				if(map[i][j] == '.')
				{
					for(int k=j+1;k<M;k++)
					{
						if(map[i][k] == '#' || map[i][k] == 'O') {
							j=k;
							break;
						}
						if(map[i][k] == 'R' || map[i][k] == 'B')
						{
							map[i][j] = map[i][k];
							map[i][k] = '.';
							break;
						}
						if(k==M-1 && map[i][k] == '.')
						{
							j=M-1;
						}
					}
				}
				if(map[i][j] == 'O')
				{
					for(int k=j+1;k<M;k++)
					{
						if(map[i][k] == '#') {
							j=k;
							break;
						}
						if(map[i][k] == 'R') {
							red_die = true;
							map[i][k] = '.';
						}
						if(map[i][k] == 'B')						
						{
							blue_die = true;
							map[i][k] = '.';
						}
						if(k==M-1 && map[i][k] == '.')
						{
							j=M-1;
						}
					}
				}
				
			}
		}
	}
	static void right()
	{
		for(int i=0;i<N;i++)
		{
			for(int j=M-1;j>0;j--)
			{
				if(map[i][j] == '#' || map[i][j] == 'R' || map[i][j] == 'B') continue;
				if(map[i][j] == '.')
				{
					for(int k=j-1;k>=0;k--)
					{
						if(map[i][k] == '#' || map[i][k] == 'O') {
							j=k;
							break;
						}
						if(map[i][k] == 'R' || map[i][k] == 'B')
						{
							map[i][j] = map[i][k];
							map[i][k] = '.';
							break;
						}
						if(k==0 && map[i][k] == '.')
						{
							j=0;
						}
					}
				}
				if(map[i][j] == 'O')
				{
					for(int k=j-1;k>=0;k--)
					{
						if(map[i][k] == '#') {
							j=k;
							break;
						}
						if(map[i][k] == 'R') {
							red_die = true;
							map[i][k] = '.';
						}
						if(map[i][k] == 'B')						
						{
							blue_die = true;
							map[i][k] = '.';
						}
						if(k==0 && map[i][k] == '.')
						{
							j=0;
						}
					}
				}
				
			}
		}
	}
	static void up()
	{
		for(int j=0;j<M;j++)
		{
			for(int i=0;i<N-1;i++)
			{
				if(map[i][j] == '#' || map[i][j] == 'R' || map[i][j] == 'B') continue;
				if(map[i][j] == '.')
				{
					for(int k=i+1;k<N;k++)
					{
						if(map[k][j] == '#' || map[k][j] == 'O') {
							i=k;
							break;
						}
						if(map[k][j] == 'R' || map[k][j] == 'B')
						{
							map[i][j] = map[k][j];
							map[k][j] = '.';
							break;
						}
						if(k==N-1 && map[i][k] == '.')
						{
							i=N-1;
						}
					}
				}
				if(map[i][j] == 'O')
				{
					for(int k=i+1;k<N;k++)
					{
						if(map[k][j] == '#') {
							i=k;
							break;
						}
						if(map[k][j] == 'R') {
							red_die = true;
							map[k][j] = '.';
						}
						if(map[k][j] == 'B')						
						{
							blue_die = true;
							map[k][j] = '.';
						}
						if(k==N-1 && map[k][j] == '.')
						{
							i=N-1;
						}
					}
				}
				
			}
		}
	}
	
	static void down()
	{
		for(int j=0;j<M;j++)
		{
			for(int i=N-1;i>0;i--)
			{
				//System.out.println(j + " "+ i);
				if(map[i][j] == '#' || map[i][j] == 'R' || map[i][j] == 'B') continue;
				if(map[i][j] == '.')
				{
					for(int k=i-1;k>=0;k--)
					{
						if(map[k][j] == '#' || map[k][j] == 'O') {
							i=k;
							break;
						}
						if(map[k][j] == 'R' || map[k][j] == 'B')
						{
							map[i][j] = map[k][j];
							map[k][j] = '.';
							break;
						}
						if(k==0 && map[k][j] == '.')
						{
							i=0;
						}
					}
				}
				if(map[i][j] == 'O')
				{
					for(int k=i-1;k>=0;k--)
					{
						if(map[k][j] == '#') {
							i=k;
							break;
						}
						if(map[k][j] == 'R') {
							red_die = true;
							map[k][j] = '.';
						}
						if(map[k][j] == 'B')						
						{
							blue_die = true;
							map[k][j] = '.';
						}
						if(k==0 && map[k][j] == '.')
						{
							i=0;
						}
					}
				}
				
			}
		}
	}
	
	
	
	
	static void look_map()
	{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)
			{
				System.out.print(map[i][j]);
			}System.out.println();
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
