import java.math.BigInteger;

public class HugeInteger {
	private int[] number;

	public HugeInteger() {
		number = new int[40];
		int i;
		for(i = 0; i < 40; ++i) {
			number[i] = 0;
		}
	}

	public HugeInteger(String input) {
		number = new int[40];
		this.parse(input);
	}

	public static HugeInteger addInteger(HugeInteger former, HugeInteger latter) {
		BigInteger biformer = new BigInteger(former.toString());
		BigInteger bilatter = new BigInteger(latter.toString());
		BigInteger biresult = biformer.add(bilatter);
		HugeInteger result = new HugeInteger(biresult.toString());
		return result;
	}

	public static HugeInteger subInteger(HugeInteger former, HugeInteger latter) {
		BigInteger biformer = new BigInteger(former.toString());
		BigInteger bilatter = new BigInteger(latter.toString());
		BigInteger biresult = biformer.subtract(bilatter);
		HugeInteger result = new HugeInteger(biresult.toString());
		return result;
	}

	public static HugeInteger mulInteger(HugeInteger former, HugeInteger latter) {
		BigInteger biformer = new BigInteger(former.toString());
		BigInteger bilatter = new BigInteger(latter.toString());
		BigInteger biresult = biformer.multiply(bilatter);
		HugeInteger result = new HugeInteger(biresult.toString());
		return result;
	}

	public static HugeInteger divInteger(HugeInteger former, HugeInteger latter) {
		BigInteger biformer = new BigInteger(former.toString());
		BigInteger bilatter = new BigInteger(latter.toString());
		BigInteger biresult = biformer.divide(bilatter);
		HugeInteger result = new HugeInteger(biresult.toString());
		return result;
	}

	public static HugeInteger modInteger(HugeInteger former, HugeInteger latter) {
		BigInteger biformer = new BigInteger(former.toString());
		BigInteger bilatter = new BigInteger(latter.toString());
		BigInteger biresult = biformer.mod(bilatter);
		HugeInteger result = new HugeInteger(biresult.toString());
		return result;
	}

	public static boolean isEqualTo(HugeInteger former, HugeInteger latter) {
		BigInteger biformer = new BigInteger(former.toString());
		BigInteger bilatter = new BigInteger(latter.toString());
		return biformer.compareTo(bilatter) == 0;
	}

	public static boolean isNotEqualTo(HugeInteger former, HugeInteger latter) {
		BigInteger biformer = new BigInteger(former.toString());
		BigInteger bilatter = new BigInteger(latter.toString());
		return biformer.compareTo(bilatter) != 0;
	}

	public static boolean isGreaterThan(HugeInteger former, HugeInteger latter) {
		BigInteger biformer = new BigInteger(former.toString());
		BigInteger bilatter = new BigInteger(latter.toString());
		return biformer.compareTo(bilatter) == 1;
	}

	public static boolean isLessThan(HugeInteger former, HugeInteger latter) {
		BigInteger biformer = new BigInteger(former.toString());
		BigInteger bilatter = new BigInteger(latter.toString());
		return biformer.compareTo(bilatter) == -1;
	}

	public static boolean isGreaterThanorEqualTo(HugeInteger former, HugeInteger latter) {
		BigInteger biformer = new BigInteger(former.toString());
		BigInteger bilatter = new BigInteger(latter.toString());
		return biformer.compareTo(bilatter) >= 0;
	}

	public static boolean isLessThanorEqualTo (HugeInteger former, HugeInteger latter) {
		BigInteger biformer = new BigInteger(former.toString());
		BigInteger bilatter = new BigInteger(latter.toString());
		return biformer.compareTo(bilatter) <= 0;
	}

	public void parse(String input) {
		int i = 39, j = input.length() - 1;
		while(j >= 0 && i >= 0) {
			this.number[i--] = Character.getNumericValue(input.charAt(j--));
		}
		while(i >= 0) {
			this.number[i--] = 0;
		}
	}

	public String toString() {
		String s = new String();
		int i;
		for(i = 0; i < 40; i++) {
			if(number[i] != 0) {
				break;
			} else {
				continue;
			}
		}
		if(i == 40) {
			s += "0";
		}
		for(; i < 40; i++) {
			String tmp = Integer.toString(number[i]);
			s += tmp;
		}
		return s;
	}
}
