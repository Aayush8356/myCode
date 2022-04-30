#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int s;
		cin >> s;
		int arr_intro[s];
		int arr_epi[s];
		for (int i = 0; i < s; ++i)
		{
			cin >> arr_intro[i];
		}
		for (int i = 0; i < s; ++i)
		{
			cin >> arr_epi[i];
		}

		int sum = 0;
		for (int i = 0; i < s; ++i)
		{
			if (arr_epi[i] == 1)
			{
				sum += arr_intro[i];
			}
			int temp[arr_epi[i]];
			for (int j = 0; j < arr_epi[i]; ++j)
			{
				cin >> temp[j];
				sum += temp[j];
			}
			sum = sum - arr_intro[i];
		}
		cout << sum << endl;
	}
	return 0;
}
