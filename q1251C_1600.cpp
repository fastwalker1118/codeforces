#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++)
    {
        vector<int> maheen;
        vector<int> e;
        vector<int> o;    

        string s;
        cin >> s;
        vector<char> v(s.begin(), s.end());      
        
        for (int i = 0; i < v.size(); i++)
        {
            if (((int)v[i] - 48) % 2 == 0)
            {
                e.push_back((int)v[i] - 48);
            }
            else
            {
                o.push_back((int)v[i] - 48);
            }
        }

        int indexe = 0; //0 0
        int indexo = 0; //7 9
        int totali = e.size() + o.size();

        while (totali > 0)
        {
            if (indexe == e.size()) 
            {
                maheen.push_back(o[indexo]);
                indexo += 1;
            }
            else if (indexo == o.size())
            {
                maheen.push_back(e[indexe]);
                indexe += 1;
            }    
            else if (e[indexe] < o[indexo])
            {
                maheen.push_back(e[indexe]);
                indexe += 1;
            }
            else
            {
                maheen.push_back(o[indexo]);
                indexo += 1;
            }
            totali -= 1;
        }

        for (int i = 0; i < v.size(); i++)
        {
            cout << maheen[i];
        }
        cout << endl;
    }
}
