// stack implementation using  Arrays

#include<stdio.h>
#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;

void Push(int x){
	if (top == MAX_SIZE - 1){
		printf("Error: OverFlow\n");
		return;
	}
	A[++top] = x;
}

void Pop(){
	if (top == -1){
		printf("Error:UnderFlow\n");
		return;
	}
	top--;
}

int Top(){
	return A[top];
}

// Boolean IsEmpty(){
// 	if (top == -1){
// 		return true;
// 	}
// 	return false;
// }

void Print(){
	for (int i = 0; i <= top; ++i)
	{
		printf("%d ",A[i]);
	}
}

int main()
{
	Push(2);
	Push(3);
	Push(4);
	Push(5);
	Print();
	Pop();
	Print();

	return 0;
}