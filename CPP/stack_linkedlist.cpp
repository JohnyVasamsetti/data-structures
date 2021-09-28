// stack implementation using  linked list

#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* next;
};
struct Node* top = NULL;

void Push(int x){
	struct Node* temp = new Node();
	temp->data = x;
	temp->next = top;
	top = temp;
}

void Pop(){
	struct Node* temp;
	temp = top;
	top = top->next;
	free(temp);
}

void Print(){
	struct Node* temp = top;
	while(temp != NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}
int main()
{
	Push(1);
	Push(2);
	Push(3);
	Push(4);
	Print();
	Pop();
	Print();
	Pop();
	Print();
	return 0;
}