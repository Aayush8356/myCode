#include<iostream>
using namespace std;

void func( int& x)
{
    x = x-1;
}

int main()
{
    int n = 10;
    func(n);
    cout << n;
}
