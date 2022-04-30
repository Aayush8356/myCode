#include <iostream>
using namespace std;

bool isPowerOfTwo(int n)
{
    return (n == 0) ? false : !(n & (n - 1));
}

int main()
{
    int n;
    cin >> n;
    cout << boolalpha << isPowerOfTwo(n);
}