import java.util.*;
import java.math.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        BigInteger n,mu,z=new BigInteger("0");
        int m;
        while(sc.hasNext())
        {

            n=sc.nextBigInteger();
            mu=new BigInteger("1");
            m=sc.nextInt();
            if((n.compareTo(z)==0)&&m==0)
                break;
            for(int i=0;i<m;i++)
            {
                mu=mu.multiply(n);
            }
            System.out.println(mu);
        }
    }
}
