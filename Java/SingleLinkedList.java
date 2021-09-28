class Node{
	int data;
	Node next;
	Node(int data){
		this.data = data;
		this.next = null;
	}
}
public class SingleLinkedList{
	public Node head;

	void InsertBegin(int data){
		Node temp = new Node(data);
		if (head == null){
			head = temp;
			return;
		}
		temp.next = head;
		head = temp;
	}

	void InsertEnd(int data){
		Node temp = new Node(data);
		if (head == null){
			head = temp;
			return;
		}
		Node trav = head;
		while(trav.next != null){
			trav = trav.next;
		}
		trav.next = temp;
	}
	void InsertBefore(int data,int before){
		Node temp = new Node(data);
		if (head == null || head.data == before){
			temp.next = head;
			head = temp;
			return ;
		}
		Node trav = head.next;
		Node prev = head;
		while(trav != null && trav.data != before){
			prev = trav;
			trav = trav.next;
		}
		prev.next = temp;
		temp.next = trav;
	}
	void InsertAfter(int data,int after){
		Node temp = new Node(data);
		if (head == null ){
			InsertBegin(data);
			return ;
		}
		Node trav = head;
		while(trav.next != null && trav.data != after){
			trav = trav.next;
		}
		temp.next = trav.next;
		trav.next = temp;
	}
	void InsertPosition(int data,int position){
		Node temp = new Node(data);
		if (head == null){
			head = temp;
			return;
		}
		if (position == 1){
			temp.next = head;
			head = temp;
			return;
		}
		Node trav = head;
		int i = 2;
		while(trav.next != null && i < position){
			trav = trav.next;
			i++;
		}
		temp.next = trav.next;
		trav.next = temp;
	}

	void DelBigin(){
		if (head == null){
			return;
		}
		head = head.next;
	}

	void DelEnd(){
		if (head == null){
			return;
		}
		if (head.next == null){
			head = null;
		}
		Node trav = head;
		while(trav.next.next != null){
			trav = trav.next;
		}
		trav.next = null;
	}

	void DelPosition(int position){
		if (head == null){
			return;
		}
		if (position == 1){
			head= head.next ;
			return;
		}
		Node trav = head;
		int i = 2;
		while(trav.next != null && i < position){
			trav = trav.next;
			i++;
		}
		trav.next = trav.next.next;
	}
	void Reverse(){
		if (head == null){
			return;
		}
		Node prev = null;
		Node nextnode;
		Node current = head;
		while(current != null){
			nextnode = current.next;
			current.next = prev;
			prev = current;
			current = nextnode;
		}
		head = prev;
	}
	void Print(){
		Node temp = head;
		while (temp != null) {
			System.out.print(temp.data + " ");
			temp = temp.next;
		}
		System.out.println();
	}

	public static void main(String[] args) {
		SingleLinkedList l = new SingleLinkedList();
		l.InsertBegin(10);
		l.InsertBegin(20);
		l.InsertBegin(30);
		l.InsertBegin(40);
		l.InsertBegin(11);
		l.InsertBegin(23);
		l.InsertBegin(13);
		l.InsertBegin(111);
		l.InsertBegin(333);
		l.Print();
		l.InsertBefore(22,23);
		l.Print();
		l.InsertBefore(332,333);
		l.Print();
		l.InsertAfter(12,11);
		l.Print();
		l.InsertAfter(11,10);
		l.Print();
		// l.DelPosition(9);
		// l.DelBigin();
		// l.DelEnd();
		// l.DelPosition(1);
		// l.DelPosition(4);
		// l.Print();
		// l.Reverse();
		// l.Print();
	}
}