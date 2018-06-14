import java.io.*;
import java.math.*;
import java.util.Scanner;
public class Main{

   public static void main(String args[]) throws IOException {  
   	/*java.io.File file = new java.io.File("input.txt");
    Scanner input = new Scanner(file);
    PrintStream out = new PrintStream(new FileOutputStream("output.txt"));
	System.setOut(out);*/
	Scanner input = new Scanner(System.in);
	BigInteger[] fib = new BigInteger[1510];
    fib[0] = new BigInteger("0");
    fib[1] = new BigInteger("1");
    fib[2] = new BigInteger("1");

    for(int i=3;i<=1500;i++)
    {

    	fib[i]=fib[i-1].add(fib[i-2]);
    }
    BigInteger[] cus = new BigInteger[1510];
    cus[1] = new BigInteger("0");
    for(int i=2;i<=1500;i++)
    {
    	cus[i]=cus[i-1].add(fib[i]);
    }

   
    int n,i=1;
    BigInteger md,x,two= new BigInteger("2"),one= new BigInteger("1");
    while(true)
    {

    	n=input.nextInt();
    	if(n==0)
    		break;
    	System.out.println("Set "+i+":");
    	i++;
    	if(n==1)
    	{
    		System.out.println("0");
    		continue;
    	}
    	x=cus[n].subtract(cus[n-1]);
    	md=x.mod(two);
    	if(md.compareTo(one)==0)
    		x=x.add(one);
    	x=x.divide(two);
    	System.out.println(x.add(cus[n-1]));
    }
   }
}
