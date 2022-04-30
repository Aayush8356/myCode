#include <iostream>
using namespace std;

pair<int, int> twoOddOccuring(int arr[], int n)
{
    int x = 0;
    int a = 0;
    int b = 0;
    for (int i = 0; i < n; ++i)
        x = x ^ arr[i];
    int setB = x & (~(x - 1));
    for (int i = 0; i < n; ++i)
    {
        if ((arr[i] & setB) != 0)
            a = a ^ arr[i];
        else
            b = b ^ arr[i];
    }
    return {a, b};
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    pair<int, int> p1 = twoOddOccuring(arr, n);
    cout << "(" << p1.first << "," << p1.second << ")";
}