#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>
 
#define ll long long
using namespace std;
 
void create(vector<vector<int>>& maheen, int v, vector<char> c)
{
	vector<char> abc;
	vector<char> bac;
	for (int i = 0; i <= v; i++)
	{
		abc.push_back('a');
		abc.push_back('b');
		abc.push_back('c');
		bac.push_back('b');
		bac.push_back('a');
		bac.push_back('c');
	}
	
	for (int i = 0; i < 3; i++)
	{
		vector<int> arr;
		if (c[0] == abc[0 + i])
		{
			arr.push_back(1);
		}
		else arr.push_back(0);
		for (int j = 1; j < c.size(); j++)
		{
			if (c[j] == abc[j + i])
			{
				arr.push_back(1 + arr[j - 1]);
			}
			else arr.push_back(0 + arr[j - 1]);
		}
		maheen.push_back(arr);
	}
	for (int i = 0; i < 3; i++)
	{
		vector<int> arr;
		if (c[0] == bac[0 + i])
		{
			arr.push_back(1);
		}
		else arr.push_back(0);
		for (int j = 1; j < c.size(); j++)
		{
			if (c[j] == bac[j + i])
			{
				arr.push_back(1 + arr[j - 1]);
			}
			else arr.push_back(0 + arr[j - 1]);
		}
		maheen.push_back(arr);
	}
}
 
int main()
{
	int n, m;
	cin >> n >> m;
	string str;
	cin >> str;
	vector<char> c{ str.begin(), str.end() };
 
	vector<vector<int>> maheen;
	create(maheen, n / 2 + 1, c);
 
	for (int j = 0; j < m; j++)
	{
		int a, b;
		cin >> a >> b;
		
		vector<int> arr;
		for (int i = 0; i < 6; i++)
		{
			if (a == 1) arr.push_back(maheen[i][b - 1]);
			else arr.push_back(maheen[i][b - 1] - maheen[i][a - 2]);
		}
		sort(arr.begin(), arr.end());
 
		cout << (b - a + 1)-arr[5] << endl;
	}
}
