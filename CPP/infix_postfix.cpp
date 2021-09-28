// converting infix to postfix 
#include<iostream>
#include<stack>
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

int IsRightAssociative(char op)
{
	if(op == '$') return true;
	return false;
}

int GetOperatorWeight(char op)
{
	int weight = -1; 
	switch(op)
	{
	case '+':
	case '-':
		weight = 1;
	case '*':
	case '/':
		weight = 2;
	case '$':
		weight = 3;
	}
	return weight;
}

int HasHigherPrecedence(char op1, char op2)
{
	int op1Weight = GetOperatorWeight(op1);
	int op2Weight = GetOperatorWeight(op2);

	if(op1Weight == op2Weight)
	{
		if(IsRightAssociative(op1)) return false;
		else return true;
	}
	return op1Weight > op2Weight ?  true: false;
}

string infixtopostfix(string infix){
	stack<char> Stack;
	string postfix = "";
	for (int i = 0; i < infix.length(); ++i)
	{
		if (infix[i] == ' ' || infix[i] == ','){
			continue;
		}

		else if (IsNumericDigit(infix[i])){
			postfix += infix[i];
		}

		else if (IsOperator(infix[i])){
			while(!Stack.empty() && Stack.top() != '(' &&  HasHigherPrecedence(Stack.top() , infix[i])){
				postfix += Stack.top();
				Stack.pop();
			}
			Stack.push(infix[i]);
		}

		else if (infix[i] == '('){
			Stack.push('(');
		}

		else if (infix[i] == ')'){
			while(!Stack.empty() && infix[i]!='('){
				postfix += Stack.top();
				Stack.pop();
			}
			Stack.pop();
		}
	}

	while(!Stack.empty()){
		postfix += Stack.top();
		Stack.pop();
	}

	return postfix;
}



int main()
{
	string C;
	cout << "Enter string :" ;
	getline(cin,C);
	cout << infixtopostfix(C);
	return 0;
}