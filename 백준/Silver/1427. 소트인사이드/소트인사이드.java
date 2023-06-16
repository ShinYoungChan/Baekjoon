import java.util.*;

public class Main {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		String str = sc.next();
		char[] ch = str.toCharArray();
		Arrays.sort(ch);
		str = new String(ch);
		StringBuffer sb = new StringBuffer(str);
		System.out.println(sb.reverse().toString());
	}

}