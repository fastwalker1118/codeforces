package codeforce;
import java.util.Arrays;
import java.util.Scanner;

public class q276C_1500 {

	 public static void main(String []args){
		 
		 Scanner s = new Scanner(System.in);
		 long l = s.nextInt();
		 long q = s.nextInt();
		 long[] arr = new long[(int) l];
		 for (int i = 0; i < l; i++) {
			 arr[i] = s.nextInt();
		 }
		 Arrays.sort(arr);
		 long[] count = new long[(int) (l+1)];
		 for (int i = 0; i < l+1; i++) {
			 count[i] = 0;
		 }
		 for (int i = 0; i < q; i++) {
			 int a = s.nextInt();
			 int b = s.nextInt();
			 count[a-1] += 1;
			 count[b] += -1;
		 }
		 for (int i = 1; i < l+1; i++) {
			 count[i] = count[i-1] + count[i];
		 }
		 
		 Arrays.sort(count);
		 
		 
		 
		 long f = 0;
		 for (int i = (int) l; i >= 1; i--) {
			 f += (long)count[i] * arr[i-1];
		 }
		 
		 System.out.println(f);
	 }
}
