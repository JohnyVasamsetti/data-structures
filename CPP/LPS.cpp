#include<iostream>
using namespace std;

int main()
{
	string s = "aaaabbaa";
	int n = s.length();
	int array[n][n];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			array[i][j] = 0;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			if (i == j){
				array[i][j] = 1;
			}
			else if (i+1 == j && s[i] == s[j]){
				array[i][j] = 1;
			}
			else if (s[i] == s[j]){
				cout << i << " " << j << " " << array[i+1][j-1] <<  endl;
				if (array[i+1][j-1] == 1){
					array[i][j] = 1;
				}
			}
			else{
				array[i][j] = 0;																																										
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}