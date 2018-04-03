import java.util.*;
import java.math.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a, b, x;
        BigInteger t;
        BigInteger ans1, ans2, mo, n = new BigInteger("1"), z = new BigInteger("0");
        while (sc.hasNext()) {

            t = sc.nextBigInteger();
            a = sc.nextInt();
            b = sc.nextInt();
            if (t.compareTo(BigInteger.valueOf(1)) == 0 || a < b) {
                System.out.println("(" + t + "^" + a + "-1)/(" + t + "^" + b + "-1) is not an integer with less than 100 digits.");
                continue;
            }
            if (a == b) {
                System.out.println("(" + t + "^" + a + "-1)/(" + t + "^" + b + "-1) " + 1);
                continue;
            }
            if (a % b != 0) {
                System.out.println("(" + t + "^" + a + "-1)/(" + t + "^" + b + "-1) is not an integer with less than 100 digits.");
                continue;
            }
            if (a == 0) {
                System.out.println("(" + t + "^" + a + "-1)/(" + t + "^" + b + "-1) " + 0);
                continue;
            }
            if ((a - b) * (Math.log10(Integer.parseInt(t.toString()))) > 99) {
                System.out.println("(" + t + "^" + a + "-1)/(" + t + "^" + b + "-1) is not an integer with less than 100 digits.");
                continue;
            }
            ans1 = t.pow(a);
            ans2 = t.pow(b);
            ans1 = ans1.subtract(n);
            ans2 = ans2.subtract(n);

            if (ans2.compareTo(z) == 0) {
                System.out.println("(" + t + "^" + a + "-1)/(" + t + "^" + b + "-1) is not an integer with less than 100 digits.");
            } else {
                mo = ans1.mod(ans2);
                ans1 = ans1.divide(ans2);
                String s = ans1.toString();
                x = s.length();
                int cmp = mo.compareTo(z);
                if (x > 100 || cmp != 0) {
                    System.out.println("(" + t + "^" + a + "-1)/(" + t + "^" + b + "-1) is not an integer with less than 100 digits.");
                } else {
                    System.out.println("(" + t + "^" + a + "-1)/(" + t + "^" + b + "-1) " + ans1);
                }
            }

        }

    }
}
