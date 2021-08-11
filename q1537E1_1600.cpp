//https://codeforces.com/contest/1537/problem/E1
//solved in 2 hour and 15 minutes without looking at any problem totourials(did look at the wrong testcases)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool check(vector<char> ar1, vector<char> arr, int k)
{
    vector<char> a, b;
    for (int i = 0; i < k; i++)
    {
        a.push_back(arr[i % arr.size()]);
    }
    for (int i = 0; i < k; i++)
    {
        b.push_back(ar1[i % ar1.size()]);
    }
    for (int i = 0; i < k; i++)
    {
        if ((int)b[i] < (int)a[i])
        {
            return true;
        }
        else
        {
            if ((int)b[i] != (int)a[i])
            {
                return false;
            }
        }
    }
    return false;
}

int main()
{
    int n, k;
    string str;
    cin >> n >> k >> str;

    vector<char> arr(str.begin(), str.end());
    int index = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if ((int)arr[i] > (int)arr[0])
        {
            index = i;
            break;
        }
        if ((int)arr[i] == (int)arr[0] && i > 0)
        {
            vector<char> ar1 = { arr.begin(), arr.begin() + i };
            if (check(ar1, arr, k) == true)
            {
                index = i;
                break;
            }
        }
        if (i == arr.size() - 1)
        {
            index = arr.size();
        }
    }

    vector<char> ar = { arr.begin(), arr.begin() + index };

    int ind = 0;
    for (int i = 0; i < k; i++)
    {
        cout << ar[ind];
        ind += 1;
        if (ind == ar.size()) ind = 0;
    }
}
