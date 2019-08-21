package boj11559;

import java.util.Scanner;
import java.util.Stack;

public class Main {
	static class pair {
		int x;
		int y;

		public pair(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}

	}

	static Character[][] map;
	static Stack<pair> s;
	static boolean[][] is_visit;
	static int cnt;
	static int[] dx = { 0, -1, 1, 0 };
	static int[] dy = { -1, 0, 0, 1 };

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		map = new Character[12][6];
		int ans = 0;
		for (int i = 0; i < 12; i++) {
			String tmp = sc.next();
			for (int j = 0; j < 6; j++) {
				map[i][j] = tmp.charAt(j);
			}
		}
		//is_visit = new boolean[16][8];
		
		//clear();
		boolean is_end = false;
		while (!is_end) {
			is_end=true;
			is_visit = new boolean[16][8];
			s = new Stack<Main.pair>();
			clear();
			//printmap();
			for (int i = 0; i < 12; i++) {
				for (int j = 0; j < 6; j++) {
					if (map[i][j] != '.' && !is_visit[i][j]) {
						s = new Stack<Main.pair>();
						cnt = 0;
						find(j, i);
						if (cnt >= 4) {
							is_end=false;
							clear();
							// printmap();

						}
					}
				}
			}
			if(!is_end) {ans++; down();}
		}

		System.out.println(ans);

	}

	static void printmap() {
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				System.out.print(map[i][j]);
			}
			System.out.println();
		}
		System.out.println("\n\n");
	}

	static void find(int x, int y) {
		// System.out.println(x+" "+y);
		s.add(new pair(x, y));
		cnt++;
		is_visit[y][x] = true;
		s.add(new pair(x, y));
		for (int i = 0; i < 4; i++) {
			if (is_go(x + dx[i], y + dy[i], map[y][x])) {
				find(x + dx[i], y + dy[i]);
			}
		}
	}

	static boolean is_go(int x, int y, Character color) {
		if (x < 0 || y < 0 || x >= 6 || y >= 12)
			return false;
		if (color != map[y][x])
			return false;
		if (is_visit[y][x])
			return false;
		return true;
	}

	static void clear() {
		while (!s.empty()) {
			pair p = s.pop();
			map[p.y][p.x] = '.';
		}	
	}
	static void down() {
		for (int j = 0; j < 6; j++) {
			for (int i = 10; i >= 0; i--) {
				if (map[i + 1][j] == '.' && map[i][j] != '.') {
					for (int k = i; k >= 0; k--) {
						map[k + 1][j] = map[k][j];
					}
					map[0][j] = '.';
					i = 11;

				}
			}
		}
	}
}
