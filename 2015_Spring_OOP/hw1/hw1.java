import java.util.Scanner;
public class hw1 {
	public static void main(String[] args) {
		char check;
		do {
			System.out.println("Enter the number followed by the order : ");
			optimalMultition();
			System.out.println("Continue? Y/n(anykey) : ");
			Scanner s = new Scanner(System.in);
			check = s.next().charAt(0);
		} while(check == 'Y' || check == 'y');
	}
	
	public static void optimalMultition() {
		Mul mul = new Mul();
		Scanner s = new Scanner(System.in);
		String num = s.next();
		int n = s.nextInt();
		int len = num.length();
		
		if(n >= len) {
			System.err.println("Multiplication sign is too many.");
		} else if(n <= 0) {
			System.err.println("Multiplication sign is too less.");
		} else if(len == 10) {
			long big = Long.parseLong(num);
			if(big > 2147483647) {
				System.err.println("The input interger is too large.");
			}
		} else if(len > 10) {
			System.err.println("The input interger is too large.");
		} else {
			for(int i = 0; i < len; i++) {
				mul.count[i] = 0;
			}
			mul.begin = n;
			subMultition(num, n-1, len, mul, 0);
			System.out.println("Maximum product : " + mul.max + " = " + mul.maxp);
		}
		mul = null;
	}
	public static void subMultition(String num, int n, int len, Mul mul, int tot) {
		if(n < 0) {
			String temp = new String();
			int pos = 0;
			int ans = 1;
			mul.prep = "";
			for(int i = 0; i < mul.begin; i++) {
				temp = num.substring(pos, pos+mul.count[i]);
				mul.prep = mul.prep.concat(temp);
				mul.prep = mul.prep.concat(" * ");
				ans *= Integer.parseInt(temp);
				pos += mul.count[i];
			}
			temp = num.substring(pos);
			mul.prep = mul.prep.concat(temp);
			ans *= Integer.parseInt(temp);
			if(ans > mul.max) {
				mul.max = ans;
				mul.maxp = "";
				mul.maxp = mul.maxp.concat(mul.prep);
			}
		} else {
			for(int i = 1; i < len; i++) {
				if(tot + i < len) {
					mul.count[n] = i;
					subMultition(num, n-1, len, mul, tot+i);
				} else {
					break;
				}
			}
		}
	}
}
