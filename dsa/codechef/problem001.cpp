#include <bits/stdc++.h>
using namespace std;

bool sortbysecdesc(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second > b.second;
}

int main()
{
    int t,a=0;
    cin >> t;
    while (t--)
    {
        int n, x;
        int s, r;
        cin >> n >> x;
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; ++i)
        {
            cin >> s >> r;
            vec.push_back(make_pair(s, r));
        }
        sort(vec.begin(), vec.end(), sortbysecdesc);
        for (int i = 0; i < n; i++)
        {
            
            if (vec[i].first <= x)
            {
                cout << vec[i].second << endl;
                break;
            }
        }
    }
    return 0;
}