public class TestHugeInteger {
	public static void main(String[] args) {
		String newLine = System.getProperty("line.separator");

		String s = "60000000000000";
		String t = "60000000000000";
		HugeInteger m = new HugeInteger(s);
		HugeInteger n = new HugeInteger(t);
		int i;
		System.out.print("m = " + m + newLine);
		System.out.print("n = " + n + newLine);
		System.out.print("m + n = " + HugeInteger.addInteger(m, n) + newLine);
		System.out.print("m - n = " + HugeInteger.subInteger(m, n) + newLine);
		System.out.print("m * n = " + HugeInteger.mulInteger(m, n) + newLine);
		System.out.print("m / n = " + HugeInteger.divInteger(m, n) + newLine);
		System.out.print("m % n = " + HugeInteger.modInteger(m, n) + newLine);
		System.out.printf("(m == n) = %b" + newLine, HugeInteger.isEqualTo(m, n));
		System.out.printf("(m != n) = %b" + newLine, HugeInteger.isNotEqualTo(m, n));
		System.out.printf("(m > n) = %b" + newLine, HugeInteger.isGreaterThan(m, n));
		System.out.printf("(m < n) = %b" + newLine, HugeInteger.isLessThan(m, n));
		System.out.printf("(m >= n) = %b" + newLine, HugeInteger.isGreaterThanorEqualTo(m, n));
		System.out.printf("(m <= n) = %b" + newLine, HugeInteger.isLessThanorEqualTo(m, n));
	}
}
