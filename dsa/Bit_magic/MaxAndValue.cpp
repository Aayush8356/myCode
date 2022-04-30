#include <iostream>
#include <algorithm>
using namespace std;

bool leftshift(int n, int k)
{
    return (n & (1 << (k - 1)));
}

int maxAND(int arr[], int N)
{
    for(int i = 32 ; i >=0 ; --i)
}

int main()
{
    int t;
    cin >> t;
    int n;
    while (t--)
    {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
    }
    return 0;
}