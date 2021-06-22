// https://codeforces.com/contest/812/problem/C

package codeforce;
import java.util.*;

public class q812C_1500 {
	
	public static long maheen(long[] arr, long k) {
		
		long[] m = new long[arr.length];
		for (int i = 0; i < arr.length; i++) {
			m[i] = arr[i] + (i+1)*k;
		}
		Arrays.sort(m);
		long maheenen = 0;
		for (int i = 0; i < k; i++) {
			maheenen += m[i];
		}
		return maheenen;
		
	}

	public static void main (String args[]) {
		
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int target = s.nextInt();
		long[] arr = new long[n];
		for (int i = 0; i < n; i++) {
			arr[i] = s.nextLong();
		}
		long lovemaheen = 0;
		if (n == 1) {
			if (maheen(arr, 1) <= target) {
				lovemaheen = 1;
			}
			else {
				lovemaheen = 0;
			}
		}
		else {
			
			long low = 0;
			long high = arr.length - 1;
			
			while (low <= high) {
				long mid = (low + high) / 2;
				if (low == mid && maheen(arr, mid + 2) <= target ) {
					lovemaheen = mid + 2;
					break;
				}
				if (low == mid && maheen(arr, mid + 1) > target ) {
					lovemaheen = 0;
					break;
				}
				if (maheen(arr, mid + 1) <= target && maheen(arr, mid + 2) > target) {
					lovemaheen = mid + 1;
					break;
				}
				else if (maheen(arr, mid + 1) > target) {
					high = mid;
				}
				else if (maheen(arr, mid + 1) < target) {
					low = mid;
				}
			}
		}
		System.out.println(lovemaheen + " " + maheen(arr, lovemaheen));
	}
	
}
