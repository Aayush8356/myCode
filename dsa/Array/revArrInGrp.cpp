// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution
{
public:
    void swap(long long *a, long long *b)
    {
        long long temp = *a;
        *a = *b;
        *b = temp;
    }

    void reverse(vector<long long> &arr, long long L, long long R)
    {
        while (L < R)
        {
            swap(&arr[L], &arr[R]);
            ++L;
            --R;
        }
    }

    /*```BC question```*/

    void reverseInGroups(vector<long long> arr, int n, int k)
    {
        // code here
        if (n <= k)
        {
            reverse(arr, 0, n - 1);
            return;
        }
        int L = 0;
        int R = k - 1;
        while (R != n - 1)
        {
            reverse(arr, L, R);
            if (R + k < n - 1)
            {
                L = R + 1; // 2 + 1
                R = R + k; // 2 + 3
            }
            else if (R + k > n - 1)
            {
                L = R + 1;
                R = n - 1;
                reverse(arr, L, R);
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
        vector<long long> arr;
        int k;
        cin >> k;

        for (long long i = 0; i < n; i++)
        {
            long long x;
            cin >> x;
            arr.push_back(x);
        }
        Solution ob;
        ob.reverseInGroups(arr, n, k);

        for (long long i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
