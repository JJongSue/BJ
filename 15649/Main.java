package boj15649;

import java.util.Scanner;

public class Main {
	static int N, M;
	static StringBuilder sb = new StringBuilder();
	static int ans[];
	static boolean is_visit[];
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		ans = new int[M];
		is_visit = new boolean[N];
		printans(0);
		System.out.println(sb);
		
	}
	static void printans(int cnt)
	{
		if(cnt == M)
		{
			for(int i=0;i<M;i++)
			{
				sb.append(ans[i]).append(" ");
			}
			sb.append("\n");
			return;
		}
		for(int i=0;i<N;i++)
		{
			if(!is_visit[i])
			{
				ans[cnt]=i+1;
				is_visit[i]=true;
				printans(cnt+1);
				is_visit[i]=false;
			}			
		}
	}
}
