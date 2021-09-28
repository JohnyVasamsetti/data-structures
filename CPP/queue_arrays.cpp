// impleemting queue using arrays

#include <iostream>
using namespace std;
#define MAX_LENGTH 11 
class Queue
{
private:
	int array[MAX_LENGTH];
	int rear,front;
public:
	Queue(){
		rear = front = -1;
	}

	bool IsEmpty(){
		if (rear == -1 && front == -1){
			return true;
		}
		return false;
	}
	bool IsFull(){
		if ( (rear+1)%MAX_LENGTH == front ){
			return true;
		}
		else{
			return false;
		}
	}

	void Enqueue(int x){
		if ( IsFull() ){
			cout << "Queue is full" << endl;
			return;
		}

		else if ( IsEmpty() ){
			rear = front = 0;
		}
		
		else{
			rear = (rear + 1)%MAX_LENGTH ;
		}
		array[rear] = x;
	}
	int Dequeue(){
		if ( front == -1){
			cout << "Queue is empty" << endl;
			return -1;
		}
		else if ( front == rear ){
			front = -1;
			rear = -1;
		}
		else{
			front = (front + 1)%MAX_LENGTH ;
		}
	}
	int Front(){
		if (front == -1){
			cout << "Queue is empty" << endl;
			return -1;
		}	
		else{
			return array[front];
		}
	}

	void Print(){
		int count = (rear + MAX_LENGTH - front)% MAX_LENGTH + 1;
		for (int i = 0 ; i < count; ++i)
		{
			cout << array[ (front + i)%MAX_LENGTH ] << " ";
		}
		cout << endl ;
	}
};

int main()
{
	Queue q;
	for (int i = 0; i < 25; ++i)
	{
		q.Enqueue(i);
		q.Print();
		q.Dequeue();
	}
	q.Dequeue();
	q.Print();
	return 0;
}