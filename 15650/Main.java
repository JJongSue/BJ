package boj15650;

import java.util.Scanner;

public class Main {
	static int N, M;
	static int ans[];
	static StringBuilder sb = new StringBuilder();
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		ans = new int[M];
		printans(0,0);
		System.out.println(sb);
		
	}
	static void printans(int now, int cnt)
	{
		if(cnt == M)
		{
			for(int i=0;i<M;i++)
			{
				sb.append(ans[i]).append(" ");
			}sb.append("\n");
			return;
		}
		for(int i=now;i<N;i++)
		{
			ans[cnt] = i+1;
			printans(i+1, cnt+1);
		}
	}
}
