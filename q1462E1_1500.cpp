// https://codeforces.com/contest/1462/problem/E1
// the problem that made me switch to c++. With the same code, java got a TLE (over 2000ms), but c++ passed with 124ms

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long maheen(long long a, long long b) {
	long long maheenen = (b - 1) * b / 2;
	return maheenen;
}

int main()
{
    int t;
    cin >> t;
    for (int ii = 0; ii < t; ii++)
    {
		long long count = 0;
        int n;
        cin >> n;
        vector<int> arr;
        for (int i = 0; i < n; i++) 
        {
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }
        sort(arr.begin(), arr.end());

		for (int i = 0; i < n; i++) 
		{
			int lo = i + 2;
			int high = n - 1;

			while (lo <= high) {
				int mid = (lo + high) / 2;
				if (lo == high) {
					if (arr[mid] - arr[i] <= 2) {
						count += maheen(2, mid - i);
					}
					break;
				}
				if (arr[mid] - arr[i] > 2) {
					high = mid;
				}
				if (arr[mid] - arr[i] <= 2) {
					if (arr[mid + 1] - arr[i] <= 2) {
						if (mid + 1 == n - 1) {
							count += maheen(2, mid - i + 1);
							break;
						}
						lo = mid;
					}
					else {
						count += maheen(2, mid - i);
						break;
					}
				}
			}
		}
		cout << count << endl;
    }
}
