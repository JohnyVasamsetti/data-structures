// paranthesis balanced expression using stack

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <string>
using namespace std;

bool Balanced(char *C,int n){
	stack<char> S;
	for (int i = 0; i < n; ++i)
	{
		char t = C[i];
		if (t == '(' or t == '[' or t=='{'){
			S.push(t);
		}
		else if ( (t==')' and S.top() == '(') or (t==']' and S.top() == '[') or (t==')' and S.top() == '(') ){
			S.pop();
		}
	}
	return S.empty();
}
int main()
{
	char S[100];
	printf("Enter a string:");
	scanf("%s",S);
	if ( Balanced(S,strlen(S)) ){
		printf("It is Balanced\n");
	}
	else{
		printf("It is not Balanced\n");
	}
	return 0;
}