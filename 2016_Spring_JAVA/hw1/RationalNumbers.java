import java.math.BigDecimal;

public class RationalNumbers {
	private int numerator;
	private int denominator;


	public RationalNumbers() {
		numerator = 0;
		denominator = 1;
	}

	public RationalNumbers(int numerator, int denominator) {
		if(denominator == 0) {
			throw new NumberFormatException();
		}
		this.numerator = numerator;
		this.denominator = denominator;
	}

	public static RationalNumbers addNumbers(RationalNumbers former, RationalNumbers latter) {
		RationalNumbers tmp = new RationalNumbers();
		tmp.numerator = former.numerator * latter.denominator + former.denominator * latter.numerator;
		tmp.denominator = former.denominator * latter.denominator;
		return tmp;
	}

	public static RationalNumbers subNumbers(RationalNumbers former, RationalNumbers latter) {
		RationalNumbers tmp = new RationalNumbers();
		tmp.numerator = former.numerator * latter.denominator - former.denominator * latter.numerator;
		tmp.denominator = former.denominator * latter.denominator;
		return tmp;
	}

	public static RationalNumbers mulNumbers(RationalNumbers former, RationalNumbers latter) {
		RationalNumbers tmp = new RationalNumbers();
		tmp.numerator = former.numerator * latter.numerator;
		tmp.denominator = former.denominator * latter.denominator;
		return tmp;
	}

	public static RationalNumbers divNumbers(RationalNumbers former, RationalNumbers latter) {
		RationalNumbers tmp = new RationalNumbers();
		tmp.numerator = former.numerator * latter.denominator;
		tmp.denominator = former.denominator * latter.numerator;
		return tmp;
	}

	public static RationalNumbers reduceNumbers(RationalNumbers number) {
		if( number.numerator < 0 && number.denominator < 0 ) {
			number.numerator *= -1;
			number.denominator *= -1;
		} else if( number.denominator < 0 ) {
			number.numerator *= -1;
			number.denominator *= -1;
		}
		int g = gcd(Math.abs(number.numerator) ,Math.abs(number.denominator));
		number.numerator /= g;
		number.denominator /= g;
		return number;
	}

	public String toString() {
		return this.numerator + "/" + this.denominator;
	}

	public String toFloatValue() {
		BigDecimal tmp = new BigDecimal((float)this.numerator / (float)this.denominator);
		tmp = tmp.setScale(5, BigDecimal.ROUND_HALF_UP);
		return tmp.floatValue() + "";
	}

	public String toFloatValue(int precision) {
		BigDecimal tmp = new BigDecimal((float)this.numerator / (float)this.denominator);
		tmp = tmp.setScale(precision, BigDecimal.ROUND_HALF_UP);
		return tmp.floatValue() + "";
	}

	public static int gcd(int m, int n) {
		return n == 0 ? m : gcd(n, m % n);
	}
}
