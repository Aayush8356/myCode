// 1 0 1 0 1 0 1

#include <iostream>
using namespace std;
int main() 
{
    int t, n;
    int size, size1;
    string str;
    int max,min;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> str;
        }
        size = 0 ; size1 = 0;
        for (int i = 0; i < str.length(); ++i)
        {
            if (str[i] == '0')
                ++size1;
            else
                size++;
        }
        max = (size>size1) ? size : size1;
        min = (size<size1) ? size : size1;
    
    if( ((max&1 == 1) && (min==(max-1))) || (max%2==0))
    {
        cout << "Yes" << endl;
    }
    else
    cout << "No" << endl;
    }
    return 0;
}