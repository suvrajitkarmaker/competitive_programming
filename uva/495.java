import java.math.BigInteger;
import java.util.Scanner;

class Main
{
    public static void main(String args[])
    {
        Scanner scanner = new Scanner(System.in);

        BigInteger fib[] = new BigInteger[5010];
        BigInteger a=BigInteger.valueOf(0);
        BigInteger b=BigInteger.valueOf(1);
        fib[0]=BigInteger.valueOf(0);
        fib[1]=BigInteger.valueOf(1);
        for(int i=2;i<=5000;i++)
        {
            fib[i] = a.add(b);
            a = b;
            b = fib[i];
        }
        Scanner s=new Scanner(System.in);
        int n=0;
        while(s.hasNext())
        {
            n=scanner.nextInt();
            System.out.printf("The Fibonacci number for %d is %s\n", n, fib[n].toString());
        }
    }
}
