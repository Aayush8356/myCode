#include<iostream>
using namespace std;


int count_bits(int n)
{
    int count = 0;
    while(n != 0)
    {
        count ++;
        n = n >> 1;
    }
    return count;
}

bool leftshift(int n , int k)
{
    return (n & ( 1 << (k-1))) ;
}

int binaryTogrey(int n)
{
    int bits = count_bits(n);
    int ans = 1;
    while(bits>1)
    {
        if(leftshift(n , bits) & leftshift(n , bits-1) or !leftshift(n , bits) & !leftshift(n , bits-1)  )
        ans = ans << 1;
        else
        ans = ( ans << 1 ) + 1; 
        --bits;
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << binaryTogrey(n);
    return 0;
}