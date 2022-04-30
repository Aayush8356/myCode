#include <iostream>
using namespace std;

int main()
{
    int d,n;
    cin >> d >> n;
    n = n % 7;
    if((d-n) < 0)
        cout << d + (7-n) << endl;
    else
        cout << d - n << endl;
    return 0;
}