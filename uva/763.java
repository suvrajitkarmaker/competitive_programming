import java.io.*;
import java.math.*;
import java.util.Scanner;
public class Main{

   public static void main(String args[]) throws IOException {  
   /*	java.io.File file = new java.io.File("input.txt");
    Scanner input = new Scanner(file);
    PrintStream out = new PrintStream(new FileOutputStream("output.txt"));
	System.setOut(out);
	*/
	Scanner input = new Scanner(System.in);
	BigInteger[] fib = new BigInteger[110];
    fib[0] = new BigInteger("1");
    fib[1] = new BigInteger("2");

    for(int i=2;i<=100;i++)
    {

    	fib[i]=fib[i-1].add(fib[i-2]);
    	//System.out.println(fib[i]);
    }
    String n,m;
    BigInteger z = new BigInteger("0");
    int ct=1;
     while(input.hasNext())
     {
     	if(ct>1)
	   		{
	   			System.out.println();
	   			
	   		}
	   		ct++;
     	n=input.next();
     	m=input.next();
     	char[] t1 = n.toCharArray();
     	char[] t2 = m.toCharArray();
     	BigInteger sum=new BigInteger("0");
     	for(int i=n.length()-1,j=0;i>=0;i--,j++)
     	{
     		if(t1[j]=='1')
     			sum=sum.add(fib[i]);
     	}
     	for(int i=m.length()-1,j=0;i>=0;i--,j++)
     	{
     		if(t2[j]=='1')
     			sum=sum.add(fib[i]);
     	}
     	if(sum.compareTo(z)==0)
     	{
     		System.out.println("0");
     		continue;
     	}
	   	int f=0;
	   //if(sum.compareTo(fib[40])==-1)

	   	//	System.out.println("DSaf");
	   	int i=100,cm;
	   	while(i>=0)
	   	{
	   		cm=fib[i].compareTo(sum);
	   		if(cm==-1||cm==0)
	   			break;
	   		i--;
	   	}
	   	
	   	for(;i>=0;i--)
	   	{
	   		cm=fib[i].compareTo(sum);
	   		if(cm==-1||cm==0)
	   		{
	   			System.out.print("1");
	   			sum=sum.subtract(fib[i]);

	   		}
	   		else
	   			System.out.print("0");
	   		
	   	}
	   	System.out.println();
     	
     }


   }
}
