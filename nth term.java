 import java.nio.channels.Pipe.SourceChannel;
import java.util.Scanner;
  
 public class nterms {
 public static void main(String[] args) {
    Scanner input= new Scanner(System.in);

    System.out.print("Enter the nth term ");
    int n = input.nextInt();  
    int m= 2*n-1;                                       // nth term here indicate for rhe no.of terms not till the n digit-------
    
    for(int i = 1; i<=m; i=i+2){
            System.out.print(i+" ");

                                                            /* 
                                                    nth term = a +(n-1)d
                                                    a=i, n= digit , d= difference
                                                    nth term = 1+(n-1)2
                                                    nth term = 2n-1
                                                    */
      }
     }   
    }
