import java.util.*;
import java.math.*;

class Base {

    public static String base(String s, int n) {
        int d = s.length();
        BigInteger sum = new BigInteger("0");
        for (int i = 0, j = d - 1; i < d; i++, j--) {
            int x = s.charAt(i) - 48;
            sum = sum.add(BigInteger.valueOf(x).multiply(BigInteger.valueOf(n).pow(j)));
        }
        return sum.toString();
    }
    public static void result(BigInteger sum,int n)
    {
        int k=0,a[]=new int[10000];
        String x;
        while(sum.compareTo(BigInteger.ZERO)!=0)
        {
            x=((sum.mod(BigInteger.valueOf(n))).toString());
            a[k++]=x.charAt(0)-48;
            sum=sum.divide(BigInteger.valueOf(n));
        }
        for(int j=k-1;j>=0;j--)
        System.out.print(a[j]);
        System.out.println();
    }
}

public class Main {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n;
        while(true)
        {
            n=sc.nextInt();
            if(n==0)
                break;
            String x=sc.next(),y=sc.next();
            BigInteger p=new BigInteger(Base.base(x, n));
            BigInteger q=new BigInteger(Base.base(y, n));
            BigInteger r=p.mod(q);
            if(r.equals(BigInteger.ZERO))
                System.out.println("0");
            else
            Base.result(r, n);

        }

    }
}
