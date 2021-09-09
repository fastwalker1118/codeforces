#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>
#include<fstream>

#define ll long long
using namespace std;

int main()
{
	int t;
	cin >> t;

	for (int o = 0; o < t; o++)
	{
		int s;
		string str;
		cin >> s >> str;

		vector<char> maheen{ str.begin(), str.end() };
		int n = maheen.size();

		for (int i = 0; i < maheen.size(); i++)
		{
			if (maheen[i] == '0')
			{
				if (i < n / 2)
				{
					cout << i + 2 << "   " << n << "   " << i + 1 << "   " << n << endl;
					break;
				}
				else
				{
					cout << 1 << "   " << i + 1 << "   " << 1 << "   " << i << endl;
					break;
				}
			}
			if (i == n - 1 && maheen[i] == '1')
			{
				cout << 1 << "   " << n - 1 << "   " << 2 << "   " << n << endl;
			}
		}
	}
}

