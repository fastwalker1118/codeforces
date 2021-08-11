#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define ll long long
using namespace std;

int main()
{
    int n;
    cin >> n;

    ll sum = 0;
    vector<pair<ll, ll >> arr;
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        sum += a;
        pair<ll, ll> temp;
        temp.first = b;
        temp.second = a;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());

    ll item = 0;
    ll money = 0;

    //cout << sum << endl;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].first - item > 0)
        {
            money += (arr[i].first - item) * 2;
            item += (arr[i].first - item);
        }
        if (item >= sum)
        {
            money -= (item - sum) * 2;
            break;
        }
        money += arr[i].second;
        item += arr[i].second;
        if (item >= sum)
        {
            money -= (item - sum);
            break;
        }
    }

    cout << money << endl;
   
}
