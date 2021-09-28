// reversing a string using stack

#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;
void Reverse(char *C,int n){
	stack<char> S;
	for (int i = 0; i < n; ++i)
	{
		S.push(C[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		C[i] = S.top();
		S.pop();
	}
}
int main()
{
	char C[50];
	printf("Enter string:");
	scanf("%s",C);
	Reverse(C,strlen(C));
	printf("Reversed String is : %s \n",C);
	return 0;
}