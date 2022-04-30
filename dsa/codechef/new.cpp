// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    //Function to partition the array around the range such
    //that array is divided into three parts.

    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    void threeWayPartition(vector<int> &array, int a, int b)
    {
        // code here

        int L = 0;
        int R = array.size() - 1;
        while (L != R)
        {

            while ((array[L] <= a) and (L<R))
            {
                ++L;
            }
            while ((array[R] >= b or array[R] >= a) and (R>L))
            {
                --R;
            }

            swap(array[L], array[R]);   
        }
        R = array.size() - 1;
        while(L<R)
        {
            while(array[L]<b)
            {
                L++;
            }
            while(array[R] > b and R>L) 
            {
                R--;
            }
            swap(array[L],array[R]);
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
        int N;
        cin >> N;

        vector<int> array(N);

        for (int i = 0; i < N; i++)
        {
            cin >> array[i];
        }

        int a, b;
        cin >> a >> b;
        Solution ob;
        ob.threeWayPartition(array, a, b);
        for (int i = 0; i < N; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends