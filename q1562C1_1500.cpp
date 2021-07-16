//https://codeforces.com/contest/1526/problem/C1#

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
    int n;
    cin >> n;
 
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
 
    vector<int> current;
    long long count = 0;
    int result = 0;
 
    for (int i = 0; i < n; i++)
    {
        count += arr[i];
        if (arr[i] < 0) {
            current.push_back(arr[i]);
        }
    
        result += 1;
  
        if (count < 0)
        {
            count = count - *min_element(current.begin(), current.end());
            int index = min_element(current.begin(), current.end()) - current.begin();
            current[index] = 1;
            result -= 1;
        }
    }
    cout << result;
}


//-----------------------------------------------------------------------------------------------------------

//below is a recursion solution that will get a TLE
/*
extern int result = 0;
 
int recur(vector<int> arr, int count, int index, int maheen)
{ 
    if (count < 0) 
    {
        return 0;
    }
    if (maheen > result)
    {
        result = maheen;
    }
    if (index == arr.size()) {
        return maheen;
    }
    if (arr[index] >= 0) {
        recur(arr, count+arr[index], index + 1, maheen+1);
    }
    else {
        recur(arr, count + arr[index], index + 1, maheen + 1);
        recur(arr, count, index + 1, maheen);
    }
} 
 
int main()
{
    int n;
    cin >> n;
    
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
 
    recur(arr, 0, 0, 0);
    cout << result;
} */
