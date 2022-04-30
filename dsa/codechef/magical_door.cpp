#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    string s;
	    cin >> s;
	    int count = 0;
	    if(s[0]=='0')
	        ++count;
	    char a = s[0];
	    for(int i = 1 ; i < s.length() ; ++i)
	    {
	        if(s[i]!=a)
	        {
	           ++count;
	           a = s[i];
	        }
	        else
	        continue;
	    }
	    cout << count << endl;
	}
	return 0;
}
