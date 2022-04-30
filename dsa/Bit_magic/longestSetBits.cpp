#include<iostream>
using namespace std;

int longestSetBit(int n)
{
    int max = 0;
    int count = 0;

    while(n)
    {
        if((n&1)==1)
        {
            ++count;
        }
        else
        {
            if(max<=count)
            {
                max = count;
            }
        }
        n = n >> 1;
    }

    return max;
}