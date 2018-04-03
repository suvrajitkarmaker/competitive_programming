import java.util.*;
import java.math.*;

public class Main {

    public static void main(String[] args) {
        String[] fact = new String[370];
        BigInteger t, x;
        fact[0] = "1";
        for (int i = 1; i <= 366; i++) {
            x = new BigInteger(fact[i - 1]);
            t = (BigInteger.valueOf(i)).multiply(x);
            fact[i] = t.toString();
        }
        int s;
        Scanner sc = new Scanner(System.in);
        while (true) {
            s = sc.nextInt();
            if (s == 0) {
                break;
            }
            int a[] = new int[12];
            String xx = fact[s];
            for (int i = 0; i < xx.length(); i++) {
                a[xx.charAt(i)-'0']++;
            }

                System.out.printf("%d! --\n",s);
                System.out.printf("   (0)  %3d    (1)  %3d    (2)  %3d    (3)  %3d    (4)  %3d\n",a[0],a[1],a[2],a[3],a[4]);
                System.out.printf("   (5)  %3d    (6)  %3d    (7)  %3d    (8)  %3d    (9)  %3d\n",a[5],a[6],a[7],a[8],a[9]);

        }
    }

}
