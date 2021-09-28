// impleemting queue using linked list

#include<iostream>
using namespace std;
struct Node{
	int data;
	struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;


int Front(){
	if (front == NULL){
		cout << "Queue is empty";
		return -1;
	}
	return front->data;
}

bool IsEmpty(){
	if (front == NULL){
		return true;
	}
	return false;
}

void Enqueue(int x){
	struct Node* temp = new Node();
	temp->data = x;
	temp->next = NULL;
	if (front == NULL && rear == NULL){
		front = rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}

void Dequeue(){
	struct Node* temp = front;
	if ( IsEmpty() ){
		cout << "Under Flow \n";
	}
	else if ( front == rear ){
		front = rear = NULL;
	}
	else{
		front = front->next;
	}
	free(temp);
}

void Print(){
	struct Node* temp = front;
	while(temp != rear){
		cout << temp->data << " " ;
		temp = temp->next;
	}
	cout << temp->data << "\n" ;
}

int main()
{
	for (int i = 0; i < 25; ++i)
	{
		Enqueue(i);
	}
	Print();
	Dequeue();
	Print();
	
	return 0;
}