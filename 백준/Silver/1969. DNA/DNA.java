import java.util.*;

public class Main {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		String[] str = new String[n];
		String answer="";
		int[] ch = new int[26];
		int sum = 0;
		for(int i=0;i<n;i++)
			str[i] = sc.next();
		for(int i=0;i<m;i++) {
			Arrays.fill(ch, 0);
			for(int j=0;j<n;j++) {
				ch[str[j].charAt(i)-'A']++;
			}
			int max = 0;
			char c = 'a';
			for(int k=0;k<26;k++) {
				if(max<ch[k]) {
					max = ch[k];
					c = (char)(k+'A');
				}
			}
			sum += n-max;
			answer+=c;
		}
		System.out.println(answer);
		System.out.println(sum);
	}

}
