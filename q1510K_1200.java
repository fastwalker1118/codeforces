//https://codeforces.com/contest/1510/problem/K

package codeforce;
import java.util.*;

public class q1510K_1200 {
	
	static int[] arr_left;
	static int[] arr_right;
	static int[] sorted;
	static int n;
	
	// 632541 to 541632
	public static void maheen1(int a) { 
		// a == 1 means sort left, a == 2 means sort right
		if (a == 1) {
			for (int i = 0; i < n ; i++) {
				int temp = arr_left[i];
				arr_left[i] = arr_left[n + i];
				arr_left[n + i] = temp;
			}
		}
		else {
			for (int i = 0; i < n ; i++) {
				int temp = arr_right[i];
				arr_right[i] = arr_right[n + i];
				arr_right[n + i] = temp;
			}
		}
	}
	
	// 632541 to 365214
	public static void maheen2(int a) { 
		// a == 1 means sort left, a == 2 means sort right
		if (a == 1) {
			for (int i = 0; i < 2*n ; i = i+2) {
				int temp = arr_left[i];
				arr_left[i] = arr_left[1 + i];
				arr_left[1 + i] = temp;
			}
		}
		else {
			for (int i = 0; i < 2*n ; i = i + 2) {
				int temp = arr_right[i];
				arr_right[i] = arr_right[1 + i];
				arr_right[1 + i] = temp;
			}
		}
	}
	
	public static void main (String args[]) {
		
		Scanner s = new Scanner(System.in);
		
		n = s.nextInt();
		arr_left = new int[2*n];
		arr_right = new int[2*n];
		sorted = new int[2*n];
		for (int i = 0; i < 2*n; i++) {
			arr_left[i] = s.nextInt();
			arr_right[i] = arr_left[i];
			sorted[i] = arr_left[i];
		}
		
		Arrays.sort(sorted);
		
		int maheenenen = 0;
		for (int i = 0; i < 2*n; i++) {
			if (arr_left[i] != sorted[i]) {
				maheenenen = 1;
			}
		}
		if (maheenenen == 0) {
			System.out.println(0);
		}
		
		int result = 0;
		
		int maheenen = 1;
		
		// this for loop is for 1 aka left branch
		for (int count = 0; count < 2*n; count++) {
			if (maheenen == 0) {
				maheen1(1);
				maheenen = 1;
			}
			else {
				maheen2(1);
				maheenen = 0;
			}
			/*for (int i = 0; i < 2*n; i++) {
				System.out.print(arr_left[i] + "   ");
			}
			System.out.println();*/
			int temp = 0;
			for (int i = 0; i < arr_left.length; i++) {
				if (arr_left[i] != sorted[i]) {
					temp = 1;
				}
			}
			if (temp == 0) {
				result = count + 1;
				break;
			}
		}
		
		int m = 0;
		for (int count = 0; count < 2*n; count++) {
			if (m == 0) {
				maheen1(2);
				m = 1;
			}
			else {
				maheen2(2);
				m = 0;
			}
			int temp = 0;
			for (int i = 0; i < arr_right.length; i++) {
				if (arr_right[i] != sorted[i]) {
					temp = 1;
				}
			}
			if (temp == 0) {
				if (result != 0 && result > count) {
					result = count + 1;
				}
				if (result == 0) {
					result = count + 1;
				}
				break;
			}
		}
		
		if (maheenenen == 1) {
			if (result == 0) {
				System.out.println(-1);
			}
			else {
				System.out.println(result);
			}
		}
		
		/*for (int i = 0; i < 2*n; i++) {
			System.out.print(arr_left[i] + "   " + arr_right[i] + "   " + sorted[i]);
			System.out.println();
		}
		*/
		
	}
	
}
