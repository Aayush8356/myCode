#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[10]={0}, num[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> num[i];
        }
        int count = 0, sum = 0;

        for (int i = 0; i < n; ++i)
        {
            ++arr[num[i]];
        }


        for (int i = 0; count != 2; ++i)
        {
            if (arr[i] > 1 && count == 0)
            {
                sum = i * 2;
                break;
            }
            else if (arr[i] >= 1)
            {
                sum = sum + i;
                ++count;
            }
        }

        cout << sum << endl;
    }
    return 0;
}