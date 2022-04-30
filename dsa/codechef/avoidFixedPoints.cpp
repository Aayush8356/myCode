#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

int main()
{
    int t, n, a, i;
    int idx = 0, count = 0;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> list, num;
        idx = 0;
        count = 0;
        for (i = 0; i < n; ++i)
        {
            cin >> a;
            list.push_back(a);
            num.push_back(i + 1);
        }

        for (i = 0; i < list.size();)
        {
            if (list[i] == num[idx])
            {
                num.push_back(++n);
                count++;
            }
            else
            {
                ++i;
            }
            ++idx;
        }
        cout << count << endl;
    }
    return 0;
}