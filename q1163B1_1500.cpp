#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
bool check(vector<pair<int, int>> arr)
{
 
	int aa = 0;
	for (int i = 0; i < 10; i++)
	{
		if (arr[i].second != 1 && arr[i].second != 0)
		{
			aa = 1;
		}
	}
	if (aa == 0)
	{
		return true;
	}
	
	//--------------------------------------
 
	int cc = 0;
	for (int i = 0; i < 10; i++)
	{
		if (arr[i].second != 0) cc += 1;
	}
	if (cc == 1) return true;
 
	//--------------------------------------
 
	int a = 0;
	int counta = 0;
	int b = 0;
	int countb = 0;
	
	for (int i = 0; i < 10; i++)
	{
		if (arr[i].second != 0) a = arr[i].second;
	}
	for (int i = 0; i < 10; i++)
	{
		if (arr[i].second != 0 && arr[i].second != a) b = arr[i].second;
	}
	for (int i = 0; i < 10; i++)
	{
		if (arr[i].second == a) counta += 1;
		if (arr[i].second == b) countb += 1;
 
		if (arr[i].second != 0 && arr[i].second != a && arr[i].second != b)
		{
			return false;
		}
	}
 
	if ((a == 1 && counta == 1) || (b == 1 && countb == 1))
	{
		return true;
	}
	if (a == b + 1 && counta == 1)
	{
		return true;
	}
	if (b == a + 1 && countb == 1)
	{
		return true;
	}
	return false;
}
 
int main()
{
	vector<pair<int, int>> arr;
	for (int i = 1; i <= 10; i++)
	{
		pair<int, int> temp;
		temp.first = i;
		temp.second = 0;
		arr.push_back(temp);
	}
 
	int result = 0;
	int n;
	cin >> n;
	vector<int> ar;
 
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		arr[temp-1].second += 1;
		
		if (check(arr) == true)
		{
			result = i + 1;
		}
		
	}
 
	cout << result;
}
