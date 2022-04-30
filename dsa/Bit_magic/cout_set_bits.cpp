#include<iostream>
using namespace std;

int countSetBits(int n)
{
    if(n==0) return 0;
    int p = 0;
    while(1<<p <= n)
    {
        ++p;
    }
    --p;
    long long int x;
    x = (p * (1<<(p-1)) ) + (n-(1<<p)+1) + countSetBits((n-(1<<p)));
    return x;
}

int main()
{
    int n;
    cin >> n;
    cout << countSetBits(n);
    return 0;
}