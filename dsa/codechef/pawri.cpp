#include <iostream>
using namespace std;
string s = "pawri";

int position(string str, int a)
{
   return str.find("party" , a);
}

void change_string(string &str, int *a)
{
	if(*a == -1)
		return;
    for(int i = *a, j = 0 ; i < *a+5 ; ++i)
    {
        str[i] = s[j++];
    }
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    string str;
		cin >> str;
	    int a = str.find("party") ;
		if(a!=-1)
	    	change_string(str,&a);
	    while(a!=-1 || a < str.length()-5)
	    {
	       a = position(str,a);
	       change_string(str,&a);
	    }
	    cout << str << endl;
	}
	return 0;
}
