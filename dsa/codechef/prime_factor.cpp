#include <iostream>
#include<vector>
using namespace std;

int main()
{
    vector<long long int>arr; //Declare
    int a=8;
   while(a)
   {
       arr.push_back(a%2); //(remainder->a%2)
       a = a/2;
   }
    for(int i = arr.size()-1 ; i >= 0; --i)
    cout << arr[i] << ' ';
    return 0;
}
