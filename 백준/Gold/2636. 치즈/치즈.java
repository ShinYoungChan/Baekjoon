import java.util.*;

class Pair{
	private int x,y;
	
	public Pair(int x,int y) {
		this.x = x;
		this.y = y;
	}
	public int getX() {
		return this.x;
	}
	public int getY() {
		return this.y;
	}
}

public class Main {
	static int[][] map = new int[100][100];
	static int[][] dxdy = {{-1,0},{0,-1},{1,0},{0,1}};
	static boolean[][] visit = new boolean[100][100];
	static boolean[][] airvisit = new boolean[100][100];
	static Queue<Pair> q = new LinkedList<>();
	static int n,m;
	public static void airCheck() {
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++)
				airvisit[i][j]=false;
		}
		q.add(new Pair(0,0));
		map[0][0]=2;
		airvisit[0][0]=true;
		while(!q.isEmpty()) {
			int x = q.peek().getX();
			int y = q.peek().getY();
			q.poll();
			for(int k=0;k<4;k++) {
				int mx=x+dxdy[k][0];
				int my=y+dxdy[k][1];
				if(mx<0||mx>n-1||my<0||my>m-1||airvisit[mx][my])continue;
				if(map[mx][my]==1)continue;
				map[mx][my]=2;
				airvisit[mx][my]=true;
				q.add(new Pair(mx,my));
			}
		}
	}
	public static boolean meltCheck(int i,int j) {
		for(int k=0;k<4;k++) {
			int mx=i+dxdy[k][0];
			int my=j+dxdy[k][1];
			if(mx<0||mx>n-1||my<0||my>m-1)continue;
			if(map[mx][my]==2) return true;
		}
		return false;
	}
	public static void melt() {
		while(!q.isEmpty()) {
			int x = q.peek().getX();
			int y = q.peek().getY();
			q.poll();
			map[x][y]=0;
		}
	}
	public static void reset() {
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++)
				visit[i][j]=false;
		}
	}
	public static int bfs(int i,int j) {
		if(map[i][j]==0||visit[i][j]||map[i][j]==2)return 0;
		int sum = 1;
		q.add(new Pair(i,j));
		visit[i][j]=true;
		while(!q.isEmpty()) {
			int x = q.peek().getX();
			int y = q.peek().getY();
			q.poll();
			for(int k=0;k<4;k++) {
				int mx=x+dxdy[k][0];
				int my=y+dxdy[k][1];
				if(mx<0||mx>n-1||my<0||my>m-1||visit[mx][my])continue;
				if(map[mx][my]==2||map[mx][my]==0)continue;
				visit[mx][my]=true;
				q.add(new Pair(mx,my));
				sum++;
			}
		}
		return sum;
	}
	public static boolean check() {
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++)
				if(map[i][j]==1)return false;
		}
		return true;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				map[i][j] = sc.nextInt();
			}
		}
		boolean flag = true;
		int time = 0;
		int before = 0;
		while(flag) {
			time++;
			reset();
			airCheck();
			for(int i=0;i<n;i++) {
				for(int j=0;j<m;j++) {
					if(map[i][j]==1&&meltCheck(i,j)) {
						q.add(new Pair(i,j));
					}
				}
			}
			int size = q.size();
			melt();
			int cheese = 0;
			for(int i=0;i<n;i++) {
				for(int j=0;j<m;j++) {
					cheese += bfs(i,j);
				}
			}
			if(check()) {
				System.out.println(size==0?0:time);
				System.out.println(before==0?size:before);
				flag = false;
			}
			before = cheese;
		}
	}

}
