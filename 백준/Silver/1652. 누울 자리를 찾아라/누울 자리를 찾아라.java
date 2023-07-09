import java.util.*;

public class Main {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String[] map = new String[n];
		for(int i=0;i<n;i++) {
			map[i] = sc.next();
		}
		int cnt = 0;
		for(int i=0;i<n;i++) {
			int asd = 0;
			for(int j=0;j<n;j++) {
				if(map[i].charAt(j)=='X') {
					if(asd>=2) {
						cnt++;
					}
					asd=0;
				}
				else
					asd++;
			}
			if(asd>=2)cnt++;
		}
		System.out.printf("%d ", cnt);
		cnt = 0;
		for(int i=0;i<n;i++) {
			int asd = 0;
			for(int j=0;j<n;j++) {
				if(map[j].charAt(i)=='X') {
					if(asd>=2) {
						cnt++;
					}
					asd=0;
				}
				else
					asd++;
			}
			if(asd>=2)cnt++;
		}
		System.out.println(cnt);
	}

}
