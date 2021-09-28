// implementing single linked list

#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* next;
};
struct Node* head;

// Inserting
void InsertAtBegin(int x){
	struct Node* temp = new Node();
	temp->data = x;
	if (head != NULL){
		temp->next = head;
	}
	head = temp;
}
void InsertAtPosition(int x,int p){
	struct Node* temp = new Node();
	temp->data = x;
	if (p==1){
		temp->next = head;
		head = temp;
	}
	else{
		struct Node* trav = head;
		for (int i = 0; i < p-2; ++i)
		{
			trav =  trav->next;
		}
		temp->next = trav->next;
		trav->next = temp;
	}
}
void InsertAtEnd(int x){
	struct Node* temp = new Node();
	temp->data = x;
	if (head == NULL){
		head = temp;
	}
	else{
		struct Node* trav = head;
		while(trav->next != NULL){
			trav = trav->next;
		}
		trav->next = temp;
		temp->next = NULL;
	}
}

// Deleting
void DeleteAtBegin(){
	if (head == NULL){
		printf("Underflow\n");
		return;
	}
	else{
		struct Node* temp = head;
		head = head->next;
		free(temp);
	}
}
void DeleteAtPosition(int p){
	if (head == NULL){
		printf("Underflow\n");
		return;
	}
	struct Node* trav = head;
	if(p ==1){
		head = trav->next;
		free(trav);
		return;
	}
	for (int i = 0; i < p-2; ++i)
	{
		trav = trav->next;
		if (trav->next == NULL){
			printf("Invalid Position\n");
			return;
		}
	}
	struct Node* temp = trav->next; // nth node
	trav->next = temp->next;
	free(temp);
}
void DeleteAtEnd(){
	if (head == NULL){
		printf("Underflow\n");
		return;
	}
	struct Node* trav = head;
	if(head->next == NULL){
		head = NULL;
		free(trav);
	}
	else{
		struct Node* prev = NULL;
		while(trav->next != NULL){
			prev = trav;
			trav = trav->next;
		}
		prev->next = NULL;
		free(trav);
	}
}

// Reverse
void Reverse(){
	struct Node* current = head;
	struct Node* next;
	struct Node* prev = NULL;
	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}
void ReverseRecursive(struct Node* p){
	if (p->next == NULL){
		head = p;
		return;
	}
	ReverseRecursive(p->next);
	struct Node* q = p->next;
	q->next = p;
	p->next = NULL;
}

// Printing
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

void PrintRecursive(struct Node* p){
	if (p == NULL){
		printf("\n");
		return;
	}
	printf("%d ",p->data);
	PrintRecursive(p->next);
}

void PrintReverse(struct Node* p){
	if (p == NULL){
		printf("\n");
		return;
	}
	PrintReverse(p->next);
	printf("%d ",p->data);
}
// Main
int main()
{
	int n,i,x;
	head = NULL;
	InsertAtBegin(2);
	InsertAtEnd(4);
	InsertAtEnd(6);
	InsertAtEnd(5);
	PrintRecursive(head);
	ReverseRecursive(head);
	PrintRecursive(head);
	return 0;
}