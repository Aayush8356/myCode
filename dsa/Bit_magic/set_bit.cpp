#include<iostream>
using namespace std;

bool leftshift(int n , int k)
{
    return (n & ( 1 << (k-1))) ;
}
bool rightshift(int n , int k)
{
    return ( (n >> (k-1)) & 1) ;
}
int main()
{
    int n , k;
    cin >> n >> k;
    cout << boolalpha << leftshift(n,k) << '\n';
    cout << boolalpha << rightshift(n,k);
}