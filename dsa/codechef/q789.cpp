#include<iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int sum = 0;
        int n,a;
        cin >> n;

        for(int i = 1 ; i <= n ; ++i)
        {
            cin >> a;
            sum += a;
        }
        if(sum%2==0)
            cout << "Yes" << '\n';
        else
            cout << "No" << '\n';
    }
    return 0;
}