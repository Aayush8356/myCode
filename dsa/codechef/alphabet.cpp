#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int arr[256] = {0};
	for (int i = 0; s[i] != '\0'; ++i)
	{
		arr[s[i]]++;
	}
	int n;
	cin >> n;
	while (n--)
	{
		string substr;
		cin >> substr;
		int j = 97, k = substr.length()-1;
		bool flag = true;
		while (j < 123 && k >= 0)
		{
			if (arr[substr[k]] == 0)
			{
				flag = false;
				break;
			}
			++j;
			++k;
		}
		if (flag)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
