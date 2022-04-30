// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  vector<int > printNGE(int arr[], int n)
{
    stack<int> s;
    int res[n];
    vector<int> vec;
    for (int i = n - 1; i >= 0; i--) {
        
        if (!s.empty()) {
            while (!s.empty() && s.top() <= arr[i]) {
                s.pop();
            }
        }
        res[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }
    for (int i = 0; i < n; i++)
        {
            if(n==1)
                vec.push_back(s.top());
            else if(res[i]!=-1)
                vec.push_back(res[i]-arr[i]);
        }
        return vec;
}
    int solve(int N, int A[]) {
        // code here
        vector<int> arr = printNGE(A, N);
        bool condition = true;
        for(int i = 0 ; i < arr.size()-1 ; ++i)
        {
            if(arr[i]>arr[i+1])
            {
                condition = false;
                break;
            }
        }
        return condition;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];

        for (int i = 0; i < N; i++) cin >> A[i];
       

        Solution ob;
        cout << ob.solve(N, A) << "\n";
    }
    return 0;
}
  // } Driver Code Ends