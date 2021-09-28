// implementing double linked list

#include<stdio.h>
#include<stdlib.h>

// structure 
struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
};
struct Node* head = new Node();
// getting new node
struct Node* GetNode(int x){
	struct Node* temp = new Node();
	temp->data = x;
	temp->prev = NULL;
	temp->next = NULL;
	return temp;
}

// insertions
void InsertAtHead(int x){
	struct Node* newNode = GetNode(x);
	if (head == NULL){
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head;
	head = newNode;
}

// printing
void Print(){
	struct Node* trav = head;
	while(trav != NULL){
		printf("%d ",trav->data);
		trav = trav->next;
	}
}
void PrintRecursive(struct Node* p){
	if (p->next == NULL){
		printf("%d\n",p->data);
		return;
	}
	printf("%d ",p->data);
	PrintRecursive(p->next);
}
void PrintReverse(){
	struct Node* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}

	while(temp != NULL){
		printf("%d ",temp->data);
		temp = temp->prev;
	}
}

// main
int main()
{
	head = NULL;
	InsertAtHead(1);
	InsertAtHead(2);
	InsertAtHead(3);
	PrintRecursive(head);
	PrintReverse();
	return 0;
}