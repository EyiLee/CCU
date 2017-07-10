public class TestRationalNumbers {
	public static void main(String[] args) {
		String newLine = System.getProperty("line.separator");

		RationalNumbers tmp = new RationalNumbers();
		System.out.print("tmp = " + tmp + newLine);
		System.out.print("tmp = " + tmp.toFloatValue(2) + newLine);
		tmp = null;

		RationalNumbers a = new RationalNumbers(1,7);
		RationalNumbers b = new RationalNumbers(3,5);
		System.out.print("a = " + a + newLine);
		System.out.print("b = " + b + newLine);
		System.out.print("a + b = " + RationalNumbers.addNumbers(a, b) + newLine);
		System.out.print("a + b = " + RationalNumbers.addNumbers(a, b).toFloatValue() + newLine);
		System.out.print("a - b = " + RationalNumbers.subNumbers(a, b) + newLine);
		System.out.print("a - b = " + RationalNumbers.subNumbers(a, b).toFloatValue() + newLine);
		System.out.print("a * b = " + RationalNumbers.mulNumbers(a, b) + newLine);
		System.out.print("a * b = " + RationalNumbers.mulNumbers(a, b).toFloatValue() + newLine);
		System.out.print("a / b = " + RationalNumbers.divNumbers(a, b) + newLine);
		System.out.print("a / b = " + RationalNumbers.divNumbers(a, b).toFloatValue() + newLine);
		System.out.print("%.2a = " + a.toFloatValue(2) + newLine);
		System.out.print("%.3a = " + a.toFloatValue(3) + newLine);
		System.out.print("%.4a = " + a.toFloatValue(4) + newLine);
		System.out.print("%.2b = " + b.toFloatValue(2) + newLine);
		System.out.print("%.3b = " + b.toFloatValue(3) + newLine);
		System.out.print("%.4b = " + b.toFloatValue(4) + newLine);
		a = null;
		b = null;
	}
}
