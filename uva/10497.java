

import java.util.*;
import java.math.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger[] fib = new BigInteger[1000];
        fib[0] = new BigInteger("0");
        fib[1] = new BigInteger("0");
        fib[2] = new BigInteger("1");
        BigInteger n = new BigInteger("2");
        for(int i=3;i<=800;i++)
        {
            fib[i]=fib[i-1].add(fib[i-2]);
            fib[i]=fib[i].multiply(n);
            n=n.add(BigInteger.ONE);
        }
        int t;
        while(sc.hasNext())
        {
            t=sc.nextInt();
            if(t==-1)
                break;
              System.out.println(fib[t]);
        }
    }
}

