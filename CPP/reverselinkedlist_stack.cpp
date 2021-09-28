// reversing linked list using stack

#include<stdlib.h>
#include<stdio.h>
#include<stack>
using namespace std;

struct Node {
	int data;
	struct Node* next;
};
struct Node* head = NULL;

void Reverse(){
	if (head == NULL){
		return ;
	}

	struct Node* temp = head;
	stack<struct Node*> S;

	while(temp != NULL){
		S.push(temp);
		temp = temp->next;
	}
	temp = S.top();head = temp;

	while(!S.empty()){
		temp->next = S.top();
		S.pop();
		temp = temp->next;
	}
	temp->next = NULL;
}

void InsertAtBegin(int x){
	struct Node* temp = new Node();
	temp->data = x;
	if (head != NULL){
		temp->next = head;
	}
	head = temp;
}

void Print(){
	struct Node* temp = head;
	if (head == NULL){
		printf("List is empty.\n");
		return;
	}
	printf("List is:\n");
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	InsertAtBegin(1);
	InsertAtBegin(2);
	InsertAtBegin(3);
	Print();
	Reverse();
	Print();
	return 0;
}