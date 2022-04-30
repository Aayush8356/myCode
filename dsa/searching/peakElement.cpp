// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/* The function should return the index of any
   peak element present in the array */

// arr: input array
// n: size of array
class Solution
{
public:
    int peakElement(int arr[], int n)
    {
        // Your code here
        if (n == 2)
            return (arr[0] > arr[1]) ? 0 : 1;
        if (arr[0] > arr[1])
            return 0;
        if (arr[n - 1] > arr[n - 2])
            return n - 1;
        int L = 1;
        int R = n - 2;
        while (L + 1 != R - 1)
        {
            if ((arr[L] > arr[L - 1]) and (arr[L] > arr[L + 1]))
                return L;
            else if ((arr[R] > arr[R - 1]) and (arr[R] > arr[R + 1]))
                return R;
            else
            {
                --R;
                ++L;
            }
        }
  
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], tmp[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            tmp[i] = a[i];
        }
        bool f = 0;
        Solution ob;

        int A = ob.peakElement(tmp, n);

        if (A < 0 and A >= n)
            cout << 0 << endl;
        else
        {
            if (n == 1 and A == 0)
                f = 1;
            else if (A == 0 and a[0] >= a[1])
                f = 1;
            else if (A == n - 1 and a[n - 1] >= a[n - 2])
                f = 1;
            else if (a[A] >= a[A + 1] and a[A] >= a[A - 1])
                f = 1;
            else
                f = 0;
            cout << f << endl;
        }
    }

    return 0;
} // } Driver Code Ends