// postfix evaluation using stack
// 2 3 * 5 4 * + 9 -
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <iostream>
using namespace std;

bool IsOperator(char c){
	if ( c == '*' || c == '/' || c == '+' || c == '-' ){
		return true;
	}
	return false;
}

bool IsNumericDigit(char c){
	if ( c >= '0' && c <= '9' ){
		return true;
	}
	return false;
}

int Perform(int a , int b , char c){
	if ( c == '*') return a * b;
	else if ( c == '/') return a /b;
	else if ( c == '+') return a + b;
	else if ( c == '-') return a - b;
	else {
		printf("Invalid Character Found \n");
	}
}

int postfixevalution(string C,int n){
	stack<int> S;
	for (int i = 0; i < n; ++i){
		if (C[i] == ' ' or C[i] == ','){
			continue;
		}

		if (IsNumericDigit(C[i])){
			int operand = 0;
			while(i < n && IsNumericDigit(C[i])) {
				operand = (operand * 10) + ( C[i] - '0');
				i++;
			}
			S.push( operand );
		}

		else if(IsOperator(C[i])) {
			int a = S.top();S.pop();
			int b = S.top();S.pop();
			int res = Perform(b,a,C[i]);
			S.push(res);
		}
	}
	return S.top();
}

int main()
{
	string S;
	printf("Enter Expression:");
	getline(cin,S);
	int result = postfixevalution(S,S.length());
	cout << result << endl;
	return 0;
}