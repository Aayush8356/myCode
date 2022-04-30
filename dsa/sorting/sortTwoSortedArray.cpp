#include <iostream>
#include <vector>

void printSorted(std::vector<int> &arr1, std::vector<int> &arr2)
{
}

int main()
{
    int N1 = 0, N2 = 0;
    std::cin >> N1 >> N2;
    std::vector<int> arr1(N1);
    std::vector<int> arr2(N2);
    printSorted(arr1, arr2);
    for (int i = 0; i < N1; ++i)
    {
        std::cin >> arr1[i];
    }
    for (int i = 0; i < N2; ++i)
    {
        std::cin >> arr2[i];
    }
}
