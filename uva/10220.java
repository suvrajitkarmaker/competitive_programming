import java.util.*;
import java.math.*;

public class Main {

    public static void main(String[] args) {
       BigInteger[] fact = new BigInteger[1010];
        fact[0]=new BigInteger("1");
        for (int i = 1; i <= 1000; i++) {
            fact[i] = (BigInteger.valueOf(i)).multiply(fact[i-1]);
        }
        int s;
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            s = sc.nextInt();
            long sum=0;
            String x=fact[s].toString();
            int d=x.length();
            for (int i = 0; i <d; i++) {
                sum+=x.charAt(i)-'0';
            }
            System.out.println(sum);

        }
    }

}
