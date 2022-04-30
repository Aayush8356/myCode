#include <iostream>
#include <vector>
using namespace std;

// int power_of_two(int length)
// {
//     return (1<<length);
// }
pair<vector<string>, int> power_set(string str)
{
    int length = str.length();
    int total_size = (1 << length);
    vector<string> s;

    for (int i = 0; i < total_size; ++i)
    {
        string xxx = "";
        for (int j = 0; j < length; ++j)
        {
            if ((i & (1 << j)) != 0)
            {
                xxx = xxx + str[j];
            }
        }
        s.push_back(xxx);
    }
    return {s, total_size};
}

int main()
{
    string str;
    cin >> str;
    pair<vector<string>, int> p = power_set(str);
    for (int i = 0; i < p.second; ++i)
        cout << p.first[i] << '\n';
    return 0;
}